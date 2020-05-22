namespace orders
{
    partial class orderForm
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
            this.props = new System.Windows.Forms.GroupBox();
            this.descBox = new System.Windows.Forms.GroupBox();
            this.desc = new System.Windows.Forms.RichTextBox();
            this.manuf = new System.Windows.Forms.Label();
            this.price = new System.Windows.Forms.Label();
            this.itemLabel = new System.Windows.Forms.Label();
            this.items = new System.Windows.Forms.ComboBox();
            this.orderBox = new System.Windows.Forms.GroupBox();
            this.order = new System.Windows.Forms.RichTextBox();
            this.addBtn = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.newBtn = new System.Windows.Forms.Button();
            this.saveBtn = new System.Windows.Forms.Button();
            this.resultBox = new System.Windows.Forms.GroupBox();
            this.result = new System.Windows.Forms.Label();
            this.fileBtn = new System.Windows.Forms.Button();
            this.openFile = new System.Windows.Forms.OpenFileDialog();
            this.saveFile = new System.Windows.Forms.SaveFileDialog();
            this.props.SuspendLayout();
            this.descBox.SuspendLayout();
            this.orderBox.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.resultBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // props
            // 
            this.props.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.props.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.props.Controls.Add(this.descBox);
            this.props.Controls.Add(this.manuf);
            this.props.Controls.Add(this.price);
            this.props.Controls.Add(this.itemLabel);
            this.props.Controls.Add(this.items);
            this.props.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.props.Location = new System.Drawing.Point(3, 3);
            this.props.Name = "props";
            this.props.Size = new System.Drawing.Size(513, 344);
            this.props.TabIndex = 2;
            this.props.TabStop = false;
            this.props.Text = "Характеристики";
            // 
            // descBox
            // 
            this.descBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.descBox.Controls.Add(this.desc);
            this.descBox.Location = new System.Drawing.Point(6, 171);
            this.descBox.Name = "descBox";
            this.descBox.Size = new System.Drawing.Size(496, 167);
            this.descBox.TabIndex = 6;
            this.descBox.TabStop = false;
            this.descBox.Text = "Описание";
            // 
            // desc
            // 
            this.desc.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.desc.Location = new System.Drawing.Point(3, 21);
            this.desc.Name = "desc";
            this.desc.ReadOnly = true;
            this.desc.Size = new System.Drawing.Size(490, 140);
            this.desc.TabIndex = 1;
            this.desc.Text = "";
            // 
            // manuf
            // 
            this.manuf.AutoSize = true;
            this.manuf.Font = new System.Drawing.Font("Segoe Print", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.manuf.Location = new System.Drawing.Point(26, 126);
            this.manuf.Name = "manuf";
            this.manuf.Size = new System.Drawing.Size(122, 23);
            this.manuf.TabIndex = 5;
            this.manuf.Text = "Производитель: ";
            // 
            // price
            // 
            this.price.AutoSize = true;
            this.price.Font = new System.Drawing.Font("Segoe Print", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.price.Location = new System.Drawing.Point(26, 78);
            this.price.Name = "price";
            this.price.Size = new System.Drawing.Size(96, 23);
            this.price.TabIndex = 4;
            this.price.Text = "Стоимость:";
            // 
            // itemLabel
            // 
            this.itemLabel.AutoSize = true;
            this.itemLabel.Font = new System.Drawing.Font("Segoe Print", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.itemLabel.Location = new System.Drawing.Point(26, 28);
            this.itemLabel.Name = "itemLabel";
            this.itemLabel.Size = new System.Drawing.Size(49, 23);
            this.itemLabel.TabIndex = 3;
            this.itemLabel.Text = "Товар";
            // 
            // items
            // 
            this.items.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.items.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.items.DropDownWidth = 345;
            this.items.FormattingEnabled = true;
            this.items.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.items.IntegralHeight = false;
            this.items.Items.AddRange(new object[] {
            "Не выбрано"});
            this.items.Location = new System.Drawing.Point(79, 28);
            this.items.Name = "items";
            this.items.Size = new System.Drawing.Size(424, 24);
            this.items.TabIndex = 2;
            this.items.SelectedValueChanged += new System.EventHandler(this.items_SelectedValueChanged);
            // 
            // orderBox
            // 
            this.orderBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.orderBox.Controls.Add(this.order);
            this.orderBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.orderBox.Location = new System.Drawing.Point(522, 3);
            this.orderBox.Name = "orderBox";
            this.orderBox.Size = new System.Drawing.Size(419, 344);
            this.orderBox.TabIndex = 3;
            this.orderBox.TabStop = false;
            this.orderBox.Text = "Заказ";
            // 
            // order
            // 
            this.order.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.order.Location = new System.Drawing.Point(6, 22);
            this.order.Name = "order";
            this.order.ReadOnly = true;
            this.order.Size = new System.Drawing.Size(407, 316);
            this.order.TabIndex = 0;
            this.order.Text = "";
            // 
            // addBtn
            // 
            this.addBtn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.addBtn.Location = new System.Drawing.Point(3, 453);
            this.addBtn.Name = "addBtn";
            this.addBtn.Size = new System.Drawing.Size(513, 26);
            this.addBtn.TabIndex = 4;
            this.addBtn.Text = "Добавить товар в заказ";
            this.addBtn.UseVisualStyleBackColor = true;
            this.addBtn.Click += new System.EventHandler(this.addBtn_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 55F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 45F));
            this.tableLayoutPanel1.Controls.Add(this.newBtn, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.props, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.saveBtn, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.resultBox, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.orderBox, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.addBtn, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.fileBtn, 0, 2);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 70F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 10F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(944, 501);
            this.tableLayoutPanel1.TabIndex = 6;
            // 
            // newBtn
            // 
            this.newBtn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.newBtn.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.newBtn.BackColor = System.Drawing.SystemColors.ControlLight;
            this.newBtn.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.newBtn.Location = new System.Drawing.Point(522, 403);
            this.newBtn.Name = "newBtn";
            this.newBtn.Size = new System.Drawing.Size(419, 26);
            this.newBtn.TabIndex = 0;
            this.newBtn.Text = "Новый заказ";
            this.newBtn.UseVisualStyleBackColor = false;
            this.newBtn.Click += new System.EventHandler(this.newBtn_click);
            // 
            // saveBtn
            // 
            this.saveBtn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.saveBtn.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.saveBtn.Location = new System.Drawing.Point(522, 453);
            this.saveBtn.Name = "saveBtn";
            this.saveBtn.Size = new System.Drawing.Size(419, 26);
            this.saveBtn.TabIndex = 1;
            this.saveBtn.Text = "Сохранить заказ";
            this.saveBtn.UseVisualStyleBackColor = true;
            this.saveBtn.Click += new System.EventHandler(this.saveBtn_Click);
            // 
            // resultBox
            // 
            this.resultBox.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.resultBox.Controls.Add(this.result);
            this.resultBox.Location = new System.Drawing.Point(522, 353);
            this.resultBox.Name = "resultBox";
            this.resultBox.Size = new System.Drawing.Size(419, 35);
            this.resultBox.TabIndex = 5;
            this.resultBox.TabStop = false;
            this.resultBox.Text = "Итого:";
            // 
            // result
            // 
            this.result.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.result.Location = new System.Drawing.Point(3, 13);
            this.result.Name = "result";
            this.result.Size = new System.Drawing.Size(413, 13);
            this.result.TabIndex = 0;
            // 
            // fileBtn
            // 
            this.fileBtn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.fileBtn.Location = new System.Drawing.Point(3, 403);
            this.fileBtn.Name = "fileBtn";
            this.fileBtn.Size = new System.Drawing.Size(513, 26);
            this.fileBtn.TabIndex = 6;
            this.fileBtn.Text = " Открыть файл с товарами";
            this.fileBtn.UseVisualStyleBackColor = true;
            this.fileBtn.Click += new System.EventHandler(this.fileBtn_Click);
            // 
            // openFile
            // 
            this.openFile.FileName = "openFile";
            this.openFile.Filter = "dat files (*.dat)| *.dat| txt files (*.txt)|*.txt|All files (*.*)|*.*";
            // 
            // saveFile
            // 
            this.saveFile.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            this.saveFile.FilterIndex = 2;
            // 
            // orderForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoScroll = true;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ClientSize = new System.Drawing.Size(944, 501);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "orderForm";
            this.Text = "Оформление заказа";
            this.props.ResumeLayout(false);
            this.props.PerformLayout();
            this.descBox.ResumeLayout(false);
            this.orderBox.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.resultBox.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox props;
        private System.Windows.Forms.GroupBox orderBox;
        private System.Windows.Forms.Button addBtn;
        private System.Windows.Forms.Label itemLabel;
        private System.Windows.Forms.ComboBox items;
        private System.Windows.Forms.GroupBox descBox;
        private System.Windows.Forms.Label manuf;
        private System.Windows.Forms.Label price;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.GroupBox resultBox;
        private System.Windows.Forms.Label result;
        private System.Windows.Forms.Button saveBtn;
        private System.Windows.Forms.Button newBtn;
        private System.Windows.Forms.OpenFileDialog openFile;
        private System.Windows.Forms.Button fileBtn;
        private System.Windows.Forms.RichTextBox desc;
        private System.Windows.Forms.RichTextBox order;
        private System.Windows.Forms.SaveFileDialog saveFile;
    }
}

