using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace orders
{
    public partial class orderForm : Form
    {
        private string[][] itemsFields = new string[128][];
        public orderForm()
        {
            InitializeComponent();
            items.SelectedIndex = 0;
            for (int i = 0; i < 128; i++)
                itemsFields[i] = new string[16];
            fileBtn_Click(null, null); //чтобы вызвать выбор файла при старте приложения
        }

        private void saveBtn_Click(object sender, EventArgs e)
        {
            if (saveFile.ShowDialog() == DialogResult.OK)
            {
                string fileName = saveFile.FileName;
                if ((openFile.OpenFile()) != null)
                {
                    string strToWrite = order.Text + "\nИтого: " + result.Text;
                    File.WriteAllText(fileName, strToWrite);
                }
            }
        }

        private void addBtn_Click(object sender, EventArgs e)
        {
            Regex reg = new Regex(@"\d+");
            int pr;
            MatchCollection matches = reg.Matches(Convert.ToString(price.Text));
            if (matches.Count <= 0) return;
            if (!int.TryParse(matches[0].Value, out pr)) return;
            order.Text += items.SelectedItem + " - " + Convert.ToString(pr) + "\n\n";
            int resText;
            result.Text = Convert.ToString(int.TryParse(result.Text, out resText) ? resText + pr : pr);
        }

        private void fileBtn_Click(object sender, EventArgs e)
        {
            if (openFile.ShowDialog() == DialogResult.OK)
            {
                // получаем выбранный файл
                string filename = openFile.FileName;
                // читаем файл в строку
                string fileText = System.IO.File.ReadAllText(filename);
                string[] itemsFromFile = new string[128];
                itemsFromFile = fileText.Split('\n');
                int i = 0;
                items.Items.Clear();
                items.Items.Add("Не выбрано");
                items.SelectedIndex = 0;
                foreach (string fItem in itemsFromFile)
                {
                    itemsFields[i] = fItem.Split('|');
                    for(int j = 0; j < itemsFields[i].Count(); j++)
                    {
                        itemsFields[i][j] = itemsFields[i][j].Trim();
                    }
                    items.Items.Add(itemsFields[i][0]);
                    i++;
                }
            }
        }

        private void items_SelectedValueChanged(object sender, EventArgs e)
        {
            string priceVal = "Стоимость: ";
            string manufVal = "Производитель: ";
            string descVal = "";
            if (items.SelectedIndex >= 1)
            {
                int ind = items.SelectedIndex - 1;
                priceVal += itemsFields[ind][1];
                manufVal += itemsFields[ind][2];
                descVal = itemsFields[ind][3];
            }
            price.Text = priceVal;
            manuf.Text = manufVal;
            desc.Text = descVal;
        }

        private void newBtn_click(object sender, EventArgs e)
        {
            items.SelectedIndex = 0;
            order.Text = "";
            result.Text = "";
        }
    }
}
