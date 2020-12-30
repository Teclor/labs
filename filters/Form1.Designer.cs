namespace filters
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.blur = new System.Windows.Forms.Button();
            this.cont = new System.Windows.Forms.Button();
            this.emboss = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(1, 1);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(800, 600);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // blur
            // 
            this.blur.Location = new System.Drawing.Point(20, 622);
            this.blur.Name = "blur";
            this.blur.Size = new System.Drawing.Size(121, 34);
            this.blur.TabIndex = 1;
            this.blur.Text = "Размыть";
            this.blur.UseVisualStyleBackColor = true;
            this.blur.Click += new System.EventHandler(this.onBlurBtnClick);
            // 
            // cont
            // 
            this.cont.Location = new System.Drawing.Point(157, 622);
            this.cont.Name = "cont";
            this.cont.Size = new System.Drawing.Size(144, 34);
            this.cont.TabIndex = 2;
            this.cont.Text = "Контраст";
            this.cont.UseVisualStyleBackColor = true;
            this.cont.Click += new System.EventHandler(this.onContrastBtnClick);
            // 
            // emboss
            // 
            this.emboss.Location = new System.Drawing.Point(319, 622);
            this.emboss.Name = "emboss";
            this.emboss.Size = new System.Drawing.Size(135, 34);
            this.emboss.TabIndex = 3;
            this.emboss.Text = "Инверсия цветов";
            this.emboss.UseVisualStyleBackColor = true;
            this.emboss.Click += new System.EventHandler(this.onInvBtnClick);
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(591, 622);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(104, 34);
            this.button5.TabIndex = 5;
            this.button5.Text = "Лаплассиан";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.onLapBtnCLick);
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(460, 622);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(115, 34);
            this.button6.TabIndex = 4;
            this.button6.Text = "Границы";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.onBorderBtnClick);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(701, 622);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(104, 34);
            this.button1.TabIndex = 6;
            this.button1.Text = "Отразить";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.onMirrorBtnClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(808, 666);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button5);
            this.Controls.Add(this.button6);
            this.Controls.Add(this.emboss);
            this.Controls.Add(this.cont);
            this.Controls.Add(this.blur);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button blur;
        private System.Windows.Forms.Button cont;
        private System.Windows.Forms.Button emboss;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Button button1;
    }
}

