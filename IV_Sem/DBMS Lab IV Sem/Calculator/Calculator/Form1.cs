using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        String op1;
        String op2;
        char oper;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            op2 = textBox1.Text;

            double num1 = double.Parse(op1);
            double num2 = double.Parse(op2);

            double result = 0;

            switch (oper)
            {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0)
                    {
                        result = num1 / num2;
                    }
                    else
                    {
                        MessageBox.Show("Division by zero is not allowed.");
                    }
                    break;
            }
            textBox1.Text = "" + result;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "1";
            textBox1.Text = m;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "2";
            textBox1.Text = m;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "3";
            textBox1.Text = m;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "4";
            textBox1.Text = m;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "5";
            textBox1.Text = m;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "6";
            textBox1.Text = m;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "7";
            textBox1.Text = m;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "8";
            textBox1.Text = m;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "9";
            textBox1.Text = m;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            String m = textBox1.Text + "0";
            textBox1.Text = m;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            op1 = textBox1.Text;
            textBox1.Text = "";
            oper = '+';
        }

        private void button13_Click(object sender, EventArgs e)
        {
            op1 = textBox1.Text;
            textBox1.Text = "";
            oper = '-';
        }

        private void button14_Click(object sender, EventArgs e)
        {
            op1 = textBox1.Text;
            textBox1.Text = "";
            oper = '*';
        }

        private void button15_Click(object sender, EventArgs e)
        {
            op1 = textBox1.Text;
            textBox1.Text = "";
            oper = '/';
        }

        private void button16_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox1.Text);
            double m = (a * (Math.PI)) / 180;
            textBox1.Text = "" + Math.Sin(m);
        }

        private void button17_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox1.Text);
            double m = (a * (Math.PI)) / 180;
            textBox1.Text = "" + Math.Cos(m);
        }

        private void button18_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox1.Text);
            double m = (a * (Math.PI)) / 180;
            textBox1.Text = "" + Math.Tan(m);
        }

        private void button19_Click(object sender, EventArgs e)
        {
            double m = double.Parse(textBox1.Text);
            textBox1.Text = "" + Math.Log(m);
        }

        private void button20_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }
    }
}

