namespace ClientSide
{
    partial class Form1
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
            this.label6 = new System.Windows.Forms.Label();
            this.flowBox = new System.Windows.Forms.RichTextBox();
            this.sendBtn = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.answerBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.questionBox = new System.Windows.Forms.RichTextBox();
            this.connectBtn = new System.Windows.Forms.Button();
            this.nameBox = new System.Windows.Forms.TextBox();
            this.portBox = new System.Windows.Forms.TextBox();
            this.ipBox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(291, 12);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(32, 13);
            this.label6.TabIndex = 27;
            this.label6.Text = "Flow:";
            // 
            // flowBox
            // 
            this.flowBox.Location = new System.Drawing.Point(294, 40);
            this.flowBox.Name = "flowBox";
            this.flowBox.ReadOnly = true;
            this.flowBox.Size = new System.Drawing.Size(300, 299);
            this.flowBox.TabIndex = 26;
            this.flowBox.Text = "";
            // 
            // sendBtn
            // 
            this.sendBtn.Location = new System.Drawing.Point(11, 313);
            this.sendBtn.Name = "sendBtn";
            this.sendBtn.Size = new System.Drawing.Size(238, 24);
            this.sendBtn.TabIndex = 25;
            this.sendBtn.Text = "Send";
            this.sendBtn.UseVisualStyleBackColor = true;
            this.sendBtn.Click += new System.EventHandler(this.sendBtn_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(14, 275);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(45, 13);
            this.label5.TabIndex = 24;
            this.label5.Text = "Answer:";
            // 
            // answerBox
            // 
            this.answerBox.Location = new System.Drawing.Point(85, 272);
            this.answerBox.Name = "answerBox";
            this.answerBox.Size = new System.Drawing.Size(164, 20);
            this.answerBox.TabIndex = 23;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(14, 166);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 13);
            this.label4.TabIndex = 22;
            this.label4.Text = "Question:";
            // 
            // questionBox
            // 
            this.questionBox.Location = new System.Drawing.Point(11, 191);
            this.questionBox.Name = "questionBox";
            this.questionBox.Size = new System.Drawing.Size(238, 56);
            this.questionBox.TabIndex = 21;
            this.questionBox.Text = "";
            // 
            // connectBtn
            // 
            this.connectBtn.Location = new System.Drawing.Point(17, 116);
            this.connectBtn.Name = "connectBtn";
            this.connectBtn.Size = new System.Drawing.Size(232, 24);
            this.connectBtn.TabIndex = 20;
            this.connectBtn.Text = "Connect";
            this.connectBtn.UseVisualStyleBackColor = true;
            this.connectBtn.Click += new System.EventHandler(this.connectBtn_Click);
            // 
            // nameBox
            // 
            this.nameBox.Location = new System.Drawing.Point(111, 72);
            this.nameBox.Name = "nameBox";
            this.nameBox.Size = new System.Drawing.Size(139, 20);
            this.nameBox.TabIndex = 19;
            // 
            // portBox
            // 
            this.portBox.Location = new System.Drawing.Point(111, 41);
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(139, 20);
            this.portBox.TabIndex = 18;
            // 
            // ipBox
            // 
            this.ipBox.Location = new System.Drawing.Point(111, 9);
            this.ipBox.Name = "ipBox";
            this.ipBox.Size = new System.Drawing.Size(139, 20);
            this.ipBox.TabIndex = 17;
            this.ipBox.TextChanged += new System.EventHandler(this.ipBox_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(14, 75);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(35, 13);
            this.label3.TabIndex = 16;
            this.label3.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 44);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(66, 13);
            this.label2.TabIndex = 15;
            this.label2.Text = "Port Number";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 12);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(17, 13);
            this.label1.TabIndex = 14;
            this.label1.Text = "IP";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(608, 351);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.flowBox);
            this.Controls.Add(this.sendBtn);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.answerBox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.questionBox);
            this.Controls.Add(this.connectBtn);
            this.Controls.Add(this.nameBox);
            this.Controls.Add(this.portBox);
            this.Controls.Add(this.ipBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.RichTextBox flowBox;
        private System.Windows.Forms.Button sendBtn;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox answerBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RichTextBox questionBox;
        private System.Windows.Forms.Button connectBtn;
        private System.Windows.Forms.TextBox nameBox;
        private System.Windows.Forms.TextBox portBox;
        private System.Windows.Forms.TextBox ipBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
    }
}

