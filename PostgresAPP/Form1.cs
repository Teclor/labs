using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Npgsql;

namespace lab
{
    public partial class Form1 : Form
    {
        string connStr;
        NpgsqlConnection conn;
        NpgsqlDataAdapter npgsqlDataAdapter;
        Dictionary<string, string> tableNames;
        string selectedTableName;
        DataSet DS = new DataSet();
        private static Form1 instance;
        public bool isAdmin;

        public Form1()
        {
            InitializeComponent();
            instance = this;
            connStr = "Host=localhost;Username=postgres;Database=company;Password=admin;";
            conn = new NpgsqlConnection(connStr);
            Login loginForm = new Login();
            loginForm.Show();
            tableNames = new Dictionary<string, string>();
            tableNames.Add("employee", "Сотрудники");
            tableNames.Add("empdata", "Данные сотрудников");
            tableNames.Add("department", "Отделения");
            tableNames.Add("position", "Должности");
            tableNames.Add("user_department_position", "Связь сотрудник-отделение-должность");
            selectedTableName = "";
            tableView.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            tableView.BackgroundColor = Color.FromArgb(240, 240, 240);
            AppDomain.CurrentDomain.UnhandledException += new UnhandledExceptionEventHandler(onError);
            initTablesComboBox();
            ascSort.Checked = true;
        }
        public static Form1 getInstance()
        {
            return instance;
        }
        public bool checkUser(string login, string password)
        {
            bool res = false;
            if (login.Length > 0 && password.Length > 0)
            {
                string query = "SELECT * FROM \"users\" WHERE (\"login\" = '" + login + "') AND (\"password\" = MD5('" + password + "'))";
                npgsqlDataAdapter.SelectCommand = new NpgsqlCommand(query, conn);
                DS = new DataSet();
                npgsqlDataAdapter.Fill(DS);
                if (DS.Tables[0].Rows.Count == 1)
                {
                    res = true;
                    isAdmin = (bool)DS.Tables[0].Rows[0]["isadmin"];
                }
            }

            return res;
        }

        private async void initTablesComboBox()
        {
            string sql = "SELECT tablename FROM pg_catalog.pg_tables WHERE schemaname != 'pg_catalog' AND schemaname != 'information_schema';";
            npgsqlDataAdapter = new NpgsqlDataAdapter(sql, conn);
            int rowsGot = -1;
            rowsGot = npgsqlDataAdapter.Fill(DS);
            tableView.DataSource = DS.Tables[0];
            foreach (DataRow data in DS.Tables[0].AsEnumerable())
            {
                string comboStr = "";
                if (data[0].ToString() == "users") 
                {
                    continue;
                }
                if (tableNames[data[0].ToString()] != null)
                {
                    comboStr = tableNames[data[0].ToString()] + " (" + data[0] + ")";
                }
                else
                {
                    comboStr = data[0].ToString();
                }
                selectTableCombo.Items.Add(comboStr);
            }
        }
        private void onSelectTableBtnClick(object sender, EventArgs e)
        {
            if (selectTableCombo.SelectedItem == null)
            {
                return;
            }
            string selectedTable = selectTableCombo.SelectedItem.ToString();
            selectedTableName = "";
            int indexOfBracket = selectedTable.IndexOf("(");
            int indexOfClosingBracket = selectedTable.IndexOf(")");
            if (indexOfBracket > 1)
            {
                selectedTableName = selectedTable.Substring(indexOfBracket+1, indexOfClosingBracket - indexOfBracket - 1);
                getSelectedTableByName();
            }
            getColumnList();

            if (isAdmin)
            {
                adminPanelLayout.Enabled = true;
            }
        }

        private void getColumnList()
        {
            columnsList.Items.Clear();
            foreach (DataGridViewColumn col in tableView.Columns)
            {
                if (col.Visible)
                {
                    columnsList.Items.Add(col.Name);
                }
            }
        }

        public void getSelectedTableByName()
        {
            if (selectedTableName == "")
            {
                return;
            }
            int rowsGot = -1;
            string query = getQuery(selectedTableName);
            npgsqlDataAdapter.SelectCommand = new NpgsqlCommand(query, conn);
            DS = new DataSet();
            rowsGot = npgsqlDataAdapter.Fill(DS);
            if (rowsGot > 0)
            {
                fillDataGridView(DS.Tables[0], selectedTableName);
            }
            DataGridViewRowCollection collect = tableView.Rows;
            tableView.Columns["id"].Visible = false;
        }

        string getQuery(string tableName)
        {
            string query = "SELECT * FROM \"" + selectedTableName + "\"";
            switch (tableName)
            {
                case "empdata":
                    query = "SELECT ED.*,  CONCAT(E.\"surname\", ' ', E.\"name\") AS employee " +
                            "FROM \"empdata\" AS ED " +
                            "JOIN \"employee\" AS E " +
                            "ON \"employee_id\" = E.\"id\"";
                    break;
                case "user_department_position":
                    query = "SELECT CONCAT(E.\"surname\", ' ', E.\"name\") AS employee,  D.\"name\" AS department, P.\"name\" AS position, UDP.\"id\" " +
                            "FROM \"user_department_position\" AS UDP " +
                            "JOIN \"employee\" AS E ON E.\"id\" = UDP.\"employee_id\" " +
                            "JOIN \"department\" AS D ON D.\"id\" = UDP.\"department_id\" " +
                            "JOIN \"position\" AS P ON  P.\"id\" = UDP.\"position_id\"";
                    break;
                default: break;
            }
            return query;
        }

        private void fillDataGridView(DataTable table, string tableName)
        {
            tableView.DataSource = new DataTable();
            switch (tableName)
            {
                case "empdata":
                    tableView.DataSource = table;
                    tableView.Columns["employee_id"].Visible = false;
                    break;
                case "user_department_position":
                    tableView.DataSource = table;
                    break;
                default:
                    tableView.DataSource = table;
                    break;
            }
        }

        private void onAddBtnClick(object sender, EventArgs e)
        {
            openModalForm("add");
        }

        private void onDeleteBtnClick(object sender, EventArgs e)
        {

            string id = tableView.SelectedRows[0].Cells["id"].Value.ToString();
            if (int.Parse(id) > 0)
            {
                string query = $"DELETE FROM \"{selectedTableName}\" WHERE \"id\" = {id}";
                conn.Open();
                NpgsqlCommand command = new NpgsqlCommand(query, conn);
                command.ExecuteNonQuery();
                conn.Close();
                getSelectedTableByName();
            }

        }

        private void onChangeBtnClick(object sender, EventArgs e)
        {
            openModalForm("edit");
        }

        public static T ConvertFromDBVal<T>(object obj)
        {
            if (obj == null || obj == DBNull.Value)
            {
                return default(T); // returns the default value for the type
            }
            else
            {
                return (T)obj;
            }
        }
        private void onDataError(object sender, DataGridViewDataErrorEventArgs e)
        {
            MessageBox.Show("Ошибка: " + e.Exception.Message);
        }
        private void onError(object sender, UnhandledExceptionEventArgs args)
        {
            Exception e = (Exception)args.ExceptionObject;
            MessageBox.Show("Ошибка: " + e.Message);
        }
        private void openModalForm(string mode)
        {
            DataGridView modalTable = new DataGridView();
            Form mForm;
            switch (mode)
            {
                case "add":
                    getEditTable(modalTable, mode);
                    mForm = new ModalForm(mode, modalTable, selectedTableName, conn, npgsqlDataAdapter);
                    mForm.Show();
                    break;
                case "edit":
                    getEditTable(modalTable, mode);
                    mForm = new ModalForm(mode, modalTable, selectedTableName, conn, npgsqlDataAdapter);
                    mForm.Show();
                    break;
                default: 
                    break;
            }
            this.Enabled = false;
        }

        private void getEditTable(DataGridView modalTableView, string mode)
        {
            modalTableView.DataError += onDataError;
            if (selectedTableName != "user_department_position")
            {
                foreach (DataGridViewColumn col in tableView.Columns)
                {
                    if ((col.Index == tableView.Columns.Count - 1) && (selectedTableName == "empdata"))
                    {
                        break;
                    }
                    else
                    {
                        DataGridViewColumn newCol = new DataGridViewColumn { CellTemplate = col.CellTemplate, Name = col.Name, HeaderText = col.HeaderText, DataPropertyName = col.DataPropertyName };
                        modalTableView.Columns.Add(newCol);
                    }
                }
                if (mode == "edit")
                {
                    string[] values = new string[selectedTableName == "empdata" ? tableView.Columns.Count - 1 : tableView.Columns.Count];
                    foreach (DataGridViewCell cell in tableView.SelectedRows[0].Cells)
                    {
                        if ((cell.ColumnIndex == tableView.Columns.Count - 1) && (selectedTableName == "empdata"))
                        {
                            break;
                        }
                        else
                        {
                            values[cell.ColumnIndex] = cell.Value.ToString();
                        }
                    }
                    modalTableView.Rows.Add(values);
                }
                else
                {
                    modalTableView.Rows.Add();
                }

            }
            else
            {
                DataGridViewColumn newCol = new DataGridViewColumn {
                    CellTemplate = tableView.Columns["id"].CellTemplate,
                    Name = tableView.Columns["id"].Name,
                    HeaderText = tableView.Columns["id"].HeaderText,
                    DataPropertyName = tableView.Columns["id"].DataPropertyName };
                modalTableView.Columns.Add(newCol);
                string[] values = { tableView.SelectedRows[0].Cells["id"].Value.ToString() };
                modalTableView.Rows.Add(values);
            }

            if (selectedTableName == "empdata" || selectedTableName == "user_department_position")
            {
                DataGridViewComboBoxColumn cmb = getComboBoxColumn("employee");
                modalTableView.Columns.Add(cmb);
                //modalTableView.Rows[0].Cells["employee_id"].Value = tableView.SelectedRows[0].Cells["employee_id"].Value;
                    //(modalTableView.Rows[0].Cells["employee_id"] as DataGridViewComboBoxCell).Items.IndexOf(tableView.SelectedRows[0].Cells["employee"].Value.ToString());
                if (selectedTableName == "user_department_position")
                {
                    DataGridViewComboBoxColumn cmb_dep = getComboBoxColumn("department");
                    modalTableView.Columns.Add(cmb_dep);
                    //modalTableView.Rows[0].Cells["department_id"].Value = tableView.SelectedRows[0].Cells["department"].Value.ToString();

                    DataGridViewComboBoxColumn cmb_pos = getComboBoxColumn("position");
                    modalTableView.Columns.Add(cmb_pos);
                    //modalTableView.Rows[0].Cells["position_id"].Value = tableView.SelectedRows[0].Cells["position"].Value.ToString();
                }
            }
        }

        public DataGridViewComboBoxColumn getComboBoxColumn(string columnName)
        {
            DataGridViewComboBoxColumn boundedValues = new DataGridViewComboBoxColumn();
            string query = "";
            if (columnName == "employee")
            {
                query = $"SELECT E.\"id\", CONCAT(E.\"surname\", ' ', E.\"name\") AS {columnName}_id FROM \"{columnName}\" as E";
            } 
            else
            {
                query = $"SELECT \"id\", \"name\" AS {columnName}_id FROM \"{columnName}\"";
            }
            npgsqlDataAdapter.SelectCommand = new NpgsqlCommand(query, conn);
            DS = new DataSet();
            npgsqlDataAdapter.Fill(DS);
            boundedValues.DataPropertyName = $"{columnName}_id";
            boundedValues.Name = $"{columnName}_id";
            boundedValues.HeaderText = columnName;
            boundedValues.DisplayMember = $"{columnName}_id";
            boundedValues.ValueMember = "id";
            boundedValues.DataSource = DS.Tables[0];
            boundedValues.DisplayIndex = 0;
            return boundedValues;
        }

        private void onSearchBtnClick(object sender, EventArgs e)
        {
            string query = buildSearchQuery();
            if (columnsList.SelectedItems.Count == 0 || query == "")
            {
                MessageBox.Show("Пожалуйста, выберите столбцы для поиска и введите поисковой запрос");
                return;
            }
            conn.Open();
            NpgsqlCommand comm = new NpgsqlCommand(query, conn);
            comm.Prepare();
            DS = new DataSet();
            npgsqlDataAdapter.SelectCommand = comm;
            npgsqlDataAdapter.Fill(DS);
            tableView.DataSource = DS.Tables[0];
            conn.Close();
        }
        
        private string buildSearchQuery()
        {
            string query = "";
            if (searchTextBox.Text.Length > 0)
            {
                query = getQuery(selectedTableName) + " WHERE (";
                int counter = 0;
                foreach (string col in columnsList.SelectedItems)
                {
                    string colName = "\"" + col + "\"";
                    if (col == "employee" || col == "department" || col == "position")
                    {
                        colName = col[0].ToString().ToUpper() + ".name";
                    }
                    query += (counter > 0 ? " OR (" : " ") + colName + " LIKE '%" + searchTextBox.Text + "%')";
                    if (col == "employee")
                    {
                        colName = col[0].ToString().ToUpper() + ".surname";
                        query += " OR (" + colName + " LIKE '%" + searchTextBox.Text + "%')";

                    }
                    counter++;
                }
            }
            return query;
        }
        
        private string buildSortQuery()
        {
            string query = buildSearchQuery();
            if (query == "")
            {
                query = getQuery(selectedTableName);
            }
            query += " ORDER BY";
            int counter = 0;
            foreach (string col in columnsList.SelectedItems)
            {
                string colName = "\"" + col + "\"";
                if (col == "employee" || col == "department" || col == "position")
                {
                    colName = col[0].ToString().ToUpper() + ".name";
                }
                query += (counter > 0 ? ", " : " ") + colName + (ascSort.Checked ? " ASC" : " DESC");
                if (col == "employee")
                {
                    colName = col[0].ToString().ToUpper() + ".surname";
                    query += ", " + colName + (ascSort.Checked ? " ASC" : " DESC");

                }
                counter++;
            }
            return query;
        }

        private void onSortBtnClick(object sender, EventArgs e)
        {
            string query = buildSortQuery();
            if (columnsList.SelectedItems.Count == 0)
            {
                MessageBox.Show("Пожалуйста, выберите столбцы для сортировки");
                return;
            }
            foreach (string col in columnsList.SelectedItems)
            {
                Console.WriteLine(col);
            }
            DS = new DataSet();
            npgsqlDataAdapter.SelectCommand = new NpgsqlCommand(query, conn);
            npgsqlDataAdapter.Fill(DS);
            tableView.DataSource = DS.Tables[0];
        }

        private void OnCalculateAvgSalaryClick(object sender, EventArgs e)
        {
            string query = "SELECT * FROM calculate_average_salary_per_department();";
            DS = new DataSet();
            npgsqlDataAdapter.SelectCommand = new NpgsqlCommand(query, conn);
            npgsqlDataAdapter.Fill(DS);
            tableView.DataSource = DS.Tables[0];
            adminPanelLayout.Enabled = false;
        }
    }
}
