namespace ServerSide
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
            this.flowBox = new System.Windows.Forms.RichTextBox();
            this.listenBtn = new System.Windows.Forms.Button();
            this.portBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.roundTextBox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.roundButton = new System.Windows.Forms.Button();
            this.startGameButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // flowBox
            // 
            this.flowBox.Location = new System.Drawing.Point(12, 110);
            this.flowBox.Name = "flowBox";
            this.flowBox.ReadOnly = true;
            this.flowBox.Size = new System.Drawing.Size(277, 248);
            this.flowBox.TabIndex = 7;
            this.flowBox.Text = "";
            // 
            // listenBtn
            // 
            this.listenBtn.Location = new System.Drawing.Point(196, 20);
            this.listenBtn.Name = "listenBtn";
            this.listenBtn.Size = new System.Drawing.Size(93, 20);
            this.listenBtn.TabIndex = 6;
            this.listenBtn.Text = "Start to Listen";
            this.listenBtn.UseVisualStyleBackColor = true;
            this.listenBtn.Click += new System.EventHandler(this.listenBtn_Click);
            // 
            // portBox
            // 
            this.portBox.Location = new System.Drawing.Point(84, 20);
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(100, 20);
            this.portBox.TabIndex = 5;
            this.portBox.TextChanged += new System.EventHandler(this.portBox_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(66, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Port Number";
            // 
            // roundTextBox
            // 
            this.roundTextBox.Location = new System.Drawing.Point(84, 46);
            this.roundTextBox.Name = "roundTextBox";
            this.roundTextBox.Size = new System.Drawing.Size(100, 20);
            this.roundTextBox.TabIndex = 8;
            this.roundTextBox.TextChanged += new System.EventHandler(this.roundTextBox_TextChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 49);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(68, 13);
            this.label2.TabIndex = 9;
            this.label2.Text = "No of rounds";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // roundButton
            // 
            this.roundButton.Location = new System.Drawing.Point(196, 46);
            this.roundButton.Name = "roundButton";
            this.roundButton.Size = new System.Drawing.Size(93, 20);
            this.roundButton.TabIndex = 10;
            this.roundButton.Text = "Send";
            this.roundButton.UseVisualStyleBackColor = true;
            this.roundButton.Click += new System.EventHandler(this.roundButton_Click);
            // 
            // startGameButton
            // 
            this.startGameButton.Location = new System.Drawing.Point(110, 72);
            this.startGameButton.Name = "startGameButton";
            this.startGameButton.Size = new System.Drawing.Size(93, 32);
            this.startGameButton.TabIndex = 11;
            this.startGameButton.Text = "Start The Game";
            this.startGameButton.UseVisualStyleBackColor = true;
            this.startGameButton.Click += new System.EventHandler(this.startGameButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(309, 372);
            this.Controls.Add(this.startGameButton);
            this.Controls.Add(this.roundButton);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.roundTextBox);
            this.Controls.Add(this.flowBox);
            this.Controls.Add(this.listenBtn);
            this.Controls.Add(this.portBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

       

        private void label2_Click(object sender, System.EventArgs e)
        {
            throw new System.NotImplementedException();
        }

        #endregion

        private System.Windows.Forms.RichTextBox flowBox;
        private System.Windows.Forms.Button listenBtn;
        private System.Windows.Forms.TextBox portBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox roundTextBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button roundButton;
        private System.Windows.Forms.Button startGameButton;
    }
}

