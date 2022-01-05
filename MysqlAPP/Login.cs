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
    public partial class Login : Form
    {
        Form1 mainForm;
        public Login()
        {
            mainForm = Form1.getInstance();
            mainForm.Enabled = false;
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void exitBtn_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void loginBtn_Click(object sender, EventArgs e)
        {
            string login = loginText.Text;
            string pass = passwordText.Text;
            bool result = mainForm.checkUser(login, pass);
            if (!result)
            {
                MessageBox.Show("Неверный логин или пароль");
            }
            else
            {
                closeForm();
            }
        }
        private void closeForm()
        {
            this.Close();
            mainForm.Enabled = true;
            mainForm.Focus();
        }

    }
}
