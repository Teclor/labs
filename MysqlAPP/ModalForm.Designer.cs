
namespace lab
{
    partial class ModalForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.modalCancelBtn = new System.Windows.Forms.Button();
            this.tableLayout = new System.Windows.Forms.TableLayoutPanel();
            this.modalSaveBtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // modalCancelBtn
            // 
            this.modalCancelBtn.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.modalCancelBtn.Font = new System.Drawing.Font("Microsoft YaHei", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.modalCancelBtn.Location = new System.Drawing.Point(12, 161);
            this.modalCancelBtn.Name = "modalCancelBtn";
            this.modalCancelBtn.Size = new System.Drawing.Size(639, 57);
            this.modalCancelBtn.TabIndex = 2;
            this.modalCancelBtn.Text = "Отмена";
            this.modalCancelBtn.UseVisualStyleBackColor = true;
            this.modalCancelBtn.Click += new System.EventHandler(this.onModalCancelClick);
            // 
            // tableLayout
            // 
            this.tableLayout.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayout.ColumnCount = 1;
            this.tableLayout.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayout.Location = new System.Drawing.Point(12, 12);
            this.tableLayout.Name = "tableLayout";
            this.tableLayout.RowCount = 1;
            this.tableLayout.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 76.2963F));
            this.tableLayout.Size = new System.Drawing.Size(1302, 138);
            this.tableLayout.TabIndex = 3;
            // 
            // modalSaveBtn
            // 
            this.modalSaveBtn.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.modalSaveBtn.Font = new System.Drawing.Font("Microsoft YaHei", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.modalSaveBtn.Location = new System.Drawing.Point(672, 161);
            this.modalSaveBtn.Name = "modalSaveBtn";
            this.modalSaveBtn.Size = new System.Drawing.Size(642, 57);
            this.modalSaveBtn.TabIndex = 1;
            this.modalSaveBtn.Text = "Применить";
            this.modalSaveBtn.UseVisualStyleBackColor = true;
            this.modalSaveBtn.Click += new System.EventHandler(this.onApplyBtnClick);
            // 
            // ModalForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1327, 225);
            this.Controls.Add(this.modalCancelBtn);
            this.Controls.Add(this.tableLayout);
            this.Controls.Add(this.modalSaveBtn);
            this.Name = "ModalForm";
            this.Text = "Изменение/добавление";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.ModalForm_FormClosed);
            this.Load += new System.EventHandler(this.ModalForm_Load);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button modalCancelBtn;
        private System.Windows.Forms.TableLayoutPanel tableLayout;
        private System.Windows.Forms.Button modalSaveBtn;
    }
}