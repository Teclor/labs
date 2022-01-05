
namespace lab
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.selectTableButton = new System.Windows.Forms.Button();
            this.selectTableCombo = new System.Windows.Forms.ComboBox();
            this.tableView = new System.Windows.Forms.DataGridView();
            this.addBtn = new System.Windows.Forms.Button();
            this.deleteBtn = new System.Windows.Forms.Button();
            this.changeBtn = new System.Windows.Forms.Button();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.adminPanelLayout = new System.Windows.Forms.FlowLayoutPanel();
            this.columnsList = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.searchTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.searchButton = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.ascSort = new System.Windows.Forms.RadioButton();
            this.descSort = new System.Windows.Forms.RadioButton();
            this.sortButton = new System.Windows.Forms.Button();
            this.CalculateAvgSalary = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.tableView)).BeginInit();
            this.adminPanelLayout.SuspendLayout();
            this.SuspendLayout();
            // 
            // selectTableButton
            // 
            this.selectTableButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.selectTableButton.Location = new System.Drawing.Point(12, 55);
            this.selectTableButton.Name = "selectTableButton";
            this.selectTableButton.Size = new System.Drawing.Size(428, 37);
            this.selectTableButton.TabIndex = 0;
            this.selectTableButton.Text = "Выбрать и получить таблицу";
            this.selectTableButton.UseVisualStyleBackColor = true;
            this.selectTableButton.Click += new System.EventHandler(this.onSelectTableBtnClick);
            // 
            // selectTableCombo
            // 
            this.selectTableCombo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.selectTableCombo.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.selectTableCombo.FormattingEnabled = true;
            this.selectTableCombo.Location = new System.Drawing.Point(13, 13);
            this.selectTableCombo.Name = "selectTableCombo";
            this.selectTableCombo.Size = new System.Drawing.Size(427, 33);
            this.selectTableCombo.TabIndex = 1;
            // 
            // tableView
            // 
            this.tableView.AllowUserToAddRows = false;
            this.tableView.AllowUserToDeleteRows = false;
            this.tableView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.tableView.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.tableView.Location = new System.Drawing.Point(457, 13);
            this.tableView.Name = "tableView";
            this.tableView.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.tableView.Size = new System.Drawing.Size(881, 410);
            this.tableView.TabIndex = 2;
            this.tableView.DataError += new System.Windows.Forms.DataGridViewDataErrorEventHandler(this.onDataError);
            // 
            // addBtn
            // 
            this.addBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.addBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.addBtn.Location = new System.Drawing.Point(3, 3);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(294, 40);
            this.addBtn.TabIndex = 3;
            this.addBtn.Text = "Добавить";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.onAddBtnClick);
            // 
            // deleteBtn
            // 
            this.deleteBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.deleteBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.deleteBtn.Location = new System.Drawing.Point(303, 3);
            this.deleteBtn.Name = "deleteBtn";
            this.deleteBtn.Size = new System.Drawing.Size(284, 40);
            this.deleteBtn.TabIndex = 4;
            this.deleteBtn.Text = "Удалить";
            this.deleteBtn.UseVisualStyleBackColor = true;
            this.deleteBtn.Click += new System.EventHandler(this.onDeleteBtnClick);
            // 
            // changeBtn
            // 
            this.changeBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.changeBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.changeBtn.Location = new System.Drawing.Point(593, 3);
            this.changeBtn.Name = "changeBtn";
            this.changeBtn.Size = new System.Drawing.Size(291, 40);
            this.changeBtn.TabIndex = 5;
            this.changeBtn.Text = "Изменить";
            this.changeBtn.UseVisualStyleBackColor = true;
            this.changeBtn.Click += new System.EventHandler(this.onChangeBtnClick);
            // 
            // adminPanelLayout
            // 
            this.adminPanelLayout.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.adminPanelLayout.Controls.Add(this.addBtn);
            this.adminPanelLayout.Controls.Add(this.deleteBtn);
            this.adminPanelLayout.Controls.Add(this.changeBtn);
            this.adminPanelLayout.Enabled = false;
            this.adminPanelLayout.Location = new System.Drawing.Point(457, 429);
            this.adminPanelLayout.Name = "adminPanelLayout";
            this.adminPanelLayout.Size = new System.Drawing.Size(887, 50);
            this.adminPanelLayout.TabIndex = 10;
            // 
            // columnsList
            // 
            this.columnsList.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.columnsList.FormattingEnabled = true;
            this.columnsList.ItemHeight = 20;
            this.columnsList.Location = new System.Drawing.Point(12, 174);
            this.columnsList.Name = "columnsList";
            this.columnsList.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.columnsList.Size = new System.Drawing.Size(428, 64);
            this.columnsList.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 137);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(428, 34);
            this.label1.TabIndex = 12;
            this.label1.Text = "Выберите столбцы для поиска/сортировки:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // searchTextBox
            // 
            this.searchTextBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.searchTextBox.Location = new System.Drawing.Point(12, 283);
            this.searchTextBox.Name = "searchTextBox";
            this.searchTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.searchTextBox.Size = new System.Drawing.Size(428, 29);
            this.searchTextBox.TabIndex = 13;
            // 
            // label2
            // 
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(12, 246);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(428, 34);
            this.label2.TabIndex = 14;
            this.label2.Text = "Введите поисковой запрос:";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // searchButton
            // 
            this.searchButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.searchButton.Location = new System.Drawing.Point(12, 318);
            this.searchButton.Name = "searchButton";
            this.searchButton.Size = new System.Drawing.Size(428, 40);
            this.searchButton.TabIndex = 15;
            this.searchButton.Text = "Искать";
            this.searchButton.UseVisualStyleBackColor = true;
            this.searchButton.Click += new System.EventHandler(this.onSearchBtnClick);
            // 
            // label3
            // 
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(12, 372);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(428, 34);
            this.label3.TabIndex = 16;
            this.label3.Text = "Выберите сортировку:";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // ascSort
            // 
            this.ascSort.AutoSize = true;
            this.ascSort.Location = new System.Drawing.Point(93, 409);
            this.ascSort.Name = "ascSort";
            this.ascSort.Size = new System.Drawing.Size(109, 17);
            this.ascSort.TabIndex = 17;
            this.ascSort.TabStop = true;
            this.ascSort.Text = "По возрастанию";
            this.ascSort.UseVisualStyleBackColor = true;
            // 
            // descSort
            // 
            this.descSort.AutoSize = true;
            this.descSort.Location = new System.Drawing.Point(259, 409);
            this.descSort.Name = "descSort";
            this.descSort.Size = new System.Drawing.Size(93, 17);
            this.descSort.TabIndex = 18;
            this.descSort.TabStop = true;
            this.descSort.Text = "По убыванию";
            this.descSort.UseVisualStyleBackColor = true;
            // 
            // sortButton
            // 
            this.sortButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.sortButton.Location = new System.Drawing.Point(12, 429);
            this.sortButton.Name = "sortButton";
            this.sortButton.Size = new System.Drawing.Size(428, 40);
            this.sortButton.TabIndex = 19;
            this.sortButton.Text = "Сортировать";
            this.sortButton.UseVisualStyleBackColor = true;
            this.sortButton.Click += new System.EventHandler(this.onSortBtnClick);
            // 
            // CalculateAvgSalary
            // 
            this.CalculateAvgSalary.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CalculateAvgSalary.Location = new System.Drawing.Point(16, 561);
            this.CalculateAvgSalary.Name = "CalculateAvgSalary";
            this.CalculateAvgSalary.Size = new System.Drawing.Size(428, 40);
            this.CalculateAvgSalary.TabIndex = 20;
            this.CalculateAvgSalary.Text = "Посчитать среднюю ЗП по отделениям";
            this.CalculateAvgSalary.UseVisualStyleBackColor = true;
            this.CalculateAvgSalary.Click += new System.EventHandler(this.OnCalculateAvgSalaryClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 728);
            this.Controls.Add(this.CalculateAvgSalary);
            this.Controls.Add(this.sortButton);
            this.Controls.Add(this.descSort);
            this.Controls.Add(this.ascSort);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.searchButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.searchTextBox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.columnsList);
            this.Controls.Add(this.adminPanelLayout);
            this.Controls.Add(this.tableView);
            this.Controls.Add(this.selectTableCombo);
            this.Controls.Add(this.selectTableButton);
            this.Name = "Form1";
            this.Text = "Сотрудники";
            ((System.ComponentModel.ISupportInitialize)(this.tableView)).EndInit();
            this.adminPanelLayout.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button selectTableButton;
        private System.Windows.Forms.ComboBox selectTableCombo;
        private System.Windows.Forms.DataGridView tableView;
        private System.Windows.Forms.Button addBtn;
        private System.Windows.Forms.Button deleteBtn;
        private System.Windows.Forms.Button changeBtn;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.FlowLayoutPanel adminPanelLayout;
        private System.Windows.Forms.ListBox columnsList;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox searchTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button searchButton;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RadioButton ascSort;
        private System.Windows.Forms.RadioButton descSort;
        private System.Windows.Forms.Button sortButton;
        private System.Windows.Forms.Button CalculateAvgSalary;
    }
}

