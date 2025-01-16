using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Threading;
using CefSharp.WinForms;
using CefSharp;
using System.Speech.Synthesis;
using NAudio.Wave;

namespace 寻找自行车
{

    public partial class Form1 : Form
    {
        List<Station> stations = new List<Station>();
        private object pictureBox1_map;

        public Form1()
        {
            InitializeComponent();
            InitializeChromium();
          

        }

        

       

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                StreamReader sr = new StreamReader(@"公共自行车站点信息.csv");
                string line = sr.ReadLine();
                line = sr.ReadLine();
                while (line != null)
                {
                    List<string> items = line.Split(',').ToList();
                    Station s = new Station();
                    s.dockNumber = int.Parse(items[3]);
                    s.stationName = items[1];
                    s.stationID = items[0];
                    s.service = int.Parse(items[4]);
                    s.lat = (items[6]);
                    s.log = (items[7]);
                    stations.Add(s);
                    comboBox1_stationID.Items.Add(items[0]);
                    comboBox2_stationID.Items.Add(items[0]);
                    line = sr.ReadLine();         
                }
                sr.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            try
            {
                StreamReader sr = new StreamReader(@"公共自行车站点信息.csv");
                string line = sr.ReadLine();
                line = sr.ReadLine();
                while (line != null)
                {
                    List<string> items = line.Split(',').ToList();
                    Station s = new Station();
                    s.dockNumber = int.Parse(items[3]);
                    s.stationName = items[1];
                    s.stationID = items[0];
                    s.service = int.Parse(items[4]);
                    s.lat = (items[6]);
                    s.log = (items[7]);
                    stations.Add(s);
                    comboBox1_stationID.Items.Add(items[0]);
                    comboBox2_stationID.Items.Add(items[0]);
                    line = sr.ReadLine();
                    float la = float.Parse(s.lat);
                    float lo = float.Parse(s.log);
                    float x, y;
                    x = (float)((lo + 87.77) / 0.33) * 513;
                    y = (float)((42.06 - la) / 0.23) * 800;
                    Graphics g = pictureBox1.CreateGraphics();
                    Pen penc = new Pen(Color.Red, 2);
                    g.DrawRectangle(penc, x, y, 1, 1);




                }
                sr.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        private Point CoConver(float log, float lat)
        {
            Point p = new Point();
            p.X = 100;
            p.Y = 100;
            return p;
        }
        public class Station
        {
            public string stationName, stationID;
            public int dockNumber;
            public int service;
            public string log, lat;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            bool flag = false;
            Point p = new Point();
            pictureBox1_map = null;
            for (int i = 0; i < stations.Count; i++)
            {
                Station s = stations[i];
                if (s.stationID == comboBox2_stationID.Text)
                {
                    textBox1_DockNum.Text = s.dockNumber.ToString();
                    textBox1_stationName.Text = s.stationName;
                    textBox1_service.Text = s.service.ToString();
                    float la = float.Parse(s.lat);
                    float lo = float.Parse(s.log);
                    float x, y;
                    x = (float)((lo + 87.77) / 0.33) * 513;
                    y = (float)((42.06 - la) / 0.23) * 800;
                    Graphics g = pictureBox1.CreateGraphics();
                    Pen penc = new Pen(Color.Red, 2);
                    g.DrawRectangle(penc, x, y, 1, 1);


                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                MessageBox.Show("No this station", "Message", MessageBoxButtons.OKCancel);
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            bool flag = false;

            for (int i = 0; i < stations.Count; i++)
            {
                Station s = stations[i];
                if (s.stationID == comboBox1_stationID.Text)
                {
                    textBox2_DockNum.Text = s.dockNumber.ToString();
                    textBox2_stationName.Text = s.stationName;
                    textBox2_service.Text = s.service.ToString();
                    float la = float.Parse(s.lat);
                    float lo = float.Parse(s.log);
                    float x, y;
                    x = (float)((lo + 87.77) / 0.33) * 513;
                    y = (float)((42.06 - la) / 0.23) * 800;
                    Graphics g = pictureBox1.CreateGraphics();
                    Pen penc = new Pen(Color.Red, 2);
                    g.DrawRectangle(penc, x, y, 1, 1);
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                MessageBox.Show("No this station", "Message", MessageBoxButtons.OKCancel);
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            comboBox1_stationID.Text = " ";
            textBox2_stationName.Text = " ";
            textBox2_DockNum.Text = " ";
            textBox2_service.Text = " ";
            pictureBox1.Refresh();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            comboBox2_stationID.Text = " ";
            textBox1_stationName.Text = " ";
            textBox1_DockNum.Text = " ";
            textBox1_service.Text = " ";
            pictureBox1.Refresh();
        }

        private void textBox2_stationName_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_stationName_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox2_stationID_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {

        }

        private void button5_Click_1(object sender, EventArgs e)
        {
            try
            {
                StreamReader sr = new StreamReader(@"公共自行车站点信息.csv");
                string line = sr.ReadLine();
                line = sr.ReadLine();
                while (line != null)
                {
                    List<string> items = line.Split(',').ToList();
                    Station s = new Station();
                    s.dockNumber = int.Parse(items[3]);
                    s.stationName = items[1];
                    s.stationID = items[0];
                    s.service = int.Parse(items[4]);
                    s.lat = (items[6]);
                    s.log = (items[7]);
                    stations.Add(s);
                    comboBox1_stationID.Items.Add(items[0]);
                    comboBox2_stationID.Items.Add(items[0]);
                    line = sr.ReadLine();
                    float la = float.Parse(s.lat);
                    float lo = float.Parse(s.log);
                    float x, y;
                    x = (float)((lo + 87.77) / 0.33) * 513;
                    y = (float)((42.06 - la) / 0.23) * 800;
                    Graphics g = pictureBox1.CreateGraphics();
                    Pen penc = new Pen(Color.Red, 2);
                    g.DrawRectangle(penc, x, y, 1, 1);
                }
                sr.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            pictureBox1.Refresh();
        }


        private void button7_Click(object sender, EventArgs e)//规划路线
        {

           
            Graphics g = pictureBox1.CreateGraphics();
            float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            for (int i = 0; i < stations.Count; i++)
            {
                Station s = stations[i];
                if (s.stationID == comboBox1_stationID.Text)
                {
                    float la = float.Parse(s.lat);
                    float lo = float.Parse(s.log);
                    float x, y;
                    x1 = (float)((lo + 87.77) / 0.33) * 513;
                    y1 = (float)((42.06 - la) / 0.23) * 800;


                    break;
                }
            }
            for (int j = 0; j < stations.Count; j++)
            {
                Station s = stations[j];
                if (s.stationID == comboBox2_stationID.Text)
                {
                    float la = float.Parse(s.lat);
                    float lo = float.Parse(s.log);
                    float x, y;
                    x2 = (float)((lo + 87.77) / 0.33) * 513;
                    y2 = (float)((42.06 - la) / 0.23) * 800;


                    break;
                }
            }
            g.DrawLine(Pens.Red, x1, y1, x2, y2);



/*
            {
                string filePath = @"ttsmaker-file-2023-12-28-9-49-39.mp3"; // 替换为实际的 MP3 文件路径

                try
                {
                    using (var reader = new Mp3FileReader(filePath))
                    using (var waveOut = new WaveOutEvent())
                    {
                        waveOut.Init(reader);
                        waveOut.Play();

                        while (waveOut.PlaybackState == PlaybackState.Playing)
                        {
                            // 等待播放完成
                        }
                    }
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"发生错误: {ex.Message}");
                }
            }*/
        }


        private void InitializeChromium()
        {
            CefSettings settings = new CefSettings();
           

            // 禁用沙盒模式
            settings.CefCommandLineArgs.Add("no-sandbox", "1");
            Cef.Initialize(settings);

            ChromiumWebBrowser chromiumWebBrowser = new ChromiumWebBrowser("https://www.google.com/maps/@41.8583373,-87.5838382,12z?hl=zh&entry=ttu");
            chromiumWebBrowser.Dock = DockStyle.Fill;

            // 将 ChromiumWebBrowser 添加到 Panel 中
            panel1.Controls.Add(chromiumWebBrowser);





            chromiumWebBrowser.FrameLoadEnd += (sender, args) =>
            {
                // 你希望设置的新缩放比例
                double newZoomLevel = 0.5;

                // 设置缩放级别
                chromiumWebBrowser.SetZoomLevel(newZoomLevel);
            };


        }


    protected override void OnFormClosing(FormClosingEventArgs e)
        {
            Cef.Shutdown();
            base.OnFormClosing(e);
        }
          

private void ChromiumWebBrowser_LoadError(object sender, LoadErrorEventArgs e)
        {
            // 处理加载错误，查看 e.ErrorText 等信息
            MessageBox.Show($"Load error: {e.ErrorText}");
        }

    }
}
    

