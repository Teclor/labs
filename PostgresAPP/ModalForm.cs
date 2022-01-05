using Npgsql;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace lab
{
    public partial class ModalForm : Form
    {
        DataGridView modalGridView;
        string selectedTableName;
        string mode;
        NpgsqlDataAdapter npgsqlDataAdapter;
        NpgsqlConnection conn;
        public ModalForm(string mode, DataGridView modalGridView, string selectedTable, NpgsqlConnection conn, NpgsqlDataAdapter mySqlDataAdapter)
        {
            InitializeComponent();
            modalGridView.Width = tableLayout.Width;
            tableLayout.AutoSize = true;
            modalGridView.Anchor = (AnchorStyles.Bottom | AnchorStyles.Right);
            modalGridView.AllowUserToAddRows = false;
            modalGridView.AllowUserToDeleteRows = false;
            modalGridView.AllowUserToOrderColumns = false;
            modalGridView.Rows[0].Visible = true;
            modalGridView.Columns["id"].Visible = false;
            modalGridView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            modalGridView.AutoSizeRowsMode = DataGridViewAutoSizeRowsMode.AllCells;
            modalGridView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            modalGridView.Font = new Font("Arial", 24F, FontStyle.Regular, GraphicsUnit.Pixel);
            modalGridView.Anchor = tableLayout.Anchor;
            tableLayout.Controls.Add(modalGridView);
            if ((selectedTable == "empdata" || selectedTable == "user-department-position") && mode == "edit")
            {
                modalGridView.Rows[0].Cells["employee_id"].Value = (modalGridView.Rows[0].Cells["employee_id"] as DataGridViewComboBoxCell).Items[0];
                if (selectedTable == "user-department-position")
                {
                    modalGridView.Rows[0].Cells["department_id"].Value = (modalGridView.Rows[0].Cells["department_id"] as DataGridViewComboBoxCell).Items[0];
                    modalGridView.Rows[0].Cells["position_id"].Value = (modalGridView.Rows[0].Cells["position_id"] as DataGridViewComboBoxCell).Items[0];
                }
            }
            this.modalGridView = modalGridView;
            this.selectedTableName = selectedTable;
            this.npgsqlDataAdapter = mySqlDataAdapter;
            this.conn = conn;
            this.mode = mode;
        }

        private void onModalCancelClick(object sender, EventArgs e)
        {
            closeForm();
        }

        private void closeForm()
        {
            Form mainForm = Application.OpenForms[0];
            this.Close();
            //mainForm.Enabled = true;
            //mainForm.Focus();
        }

        private void ModalForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Form mainForm = Application.OpenForms[0];
            mainForm.Enabled = true;
            (mainForm as Form1).getSelectedTableByName();
        }

        private void AddToDB()
        {
            modalGridView.EndEdit();
            int itemCount = 0;

            string query = "INSERT INTO \"" + selectedTableName + "\" (";

            foreach (DataGridViewColumn column in modalGridView.Columns)
            {
                if (column.Name == "id" || modalGridView.Rows[0].Cells[column.Name].Value == null)
                {
                    continue;
                }
                itemCount++;
                if (itemCount > 1 && itemCount < modalGridView.Columns.Count)
                {
                    query += ", ";
                }
                query += column.Name;
            }
            if (itemCount > 0)
            {
                itemCount = 0;
                query += ") VALUES (";
                foreach (DataGridViewRow row in modalGridView.Rows)
                {
                    foreach (DataGridViewCell elem in row.Cells)
                    {
                        if (elem.ColumnIndex == modalGridView.Columns["id"].Index || elem.Value == null)
                        {
                            continue;
                        }
                        itemCount++;
                        string item = elem.Value.ToString();
                        if (itemCount > 1 && itemCount < modalGridView.Columns.Count)
                        {
                            query += ',';
                        }
                        query += '\'' + item + '\'';
                    }
                    query += ')';

                }
                Console.WriteLine(query);
                conn.Open();
                NpgsqlCommand insertCommand = new NpgsqlCommand(query, conn);
                try
                {
                    insertCommand.ExecuteNonQuery();
                }
                catch (Exception e)
                {
                    MessageBox.Show("Ошибка: " + e.Message);
                }
                conn.Close();
            }
            else
            {
                MessageBox.Show("Не заполнены значения полей");
            }
        }

        private void UpdateInDB()
        {
            modalGridView.EndEdit();
            DataTable changes;
            int itemCount = 0;

            string query = "UPDATE \"" + selectedTableName + "\" SET ";

            foreach (DataGridViewColumn column in modalGridView.Columns)
            {
                if (column.Name == "id")
                {
                    continue;
                }
                if (itemCount > 0 && itemCount < modalGridView.Columns.Count-1)
                {
                    query += ',';
                }
                itemCount++;
                query += $"\"{column.Name}\"";
                query += " = ";
                query += $"'{modalGridView.Rows[0].Cells[column.Name].Value}'";

            }
            query += " WHERE id = ";
            query += modalGridView.Rows[0].Cells["id"].Value.ToString();
            Console.WriteLine(query);
            conn.Open();
            NpgsqlCommand updateCommand = new NpgsqlCommand(query, conn);
            try
            {
                updateCommand.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                MessageBox.Show("Ошибка: " + e.Message);
            }
            conn.Close();
        }

        private void onApplyBtnClick(object sender, EventArgs e)
        {
            if (mode == "edit")
            {
                UpdateInDB();
            }
            else if (mode == "add")
            {
                AddToDB();
            }
            else
            {
                throw new Exception("invalid mode");
            }
            closeForm();
        }
    }
}
