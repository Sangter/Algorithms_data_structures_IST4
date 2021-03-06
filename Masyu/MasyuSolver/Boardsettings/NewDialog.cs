﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Masyu.Boardsettings{
    public partial class NewDialog : Form
    {

        public int puzzleWidth, puzzleHeight;

        public NewDialog()
        {
            InitializeComponent();
        }

        // Кнопка "Ок" 
        private void button1_Click(object sender, EventArgs e)
        {

            bool wParse = int.TryParse(textBox1.Text, out puzzleWidth);
            bool hParse = int.TryParse(textBox2.Text, out puzzleHeight);

            if (wParse && hParse && puzzleHeight > 0 && puzzleHeight > 0)
            {
                DialogResult = DialogResult.OK;
                Close();
            }
        }
        // Кнопка "Отмнена"
        private void button2_Click(object sender, EventArgs e) {
            DialogResult = DialogResult.Cancel;
            Close();
        }
    }
}
