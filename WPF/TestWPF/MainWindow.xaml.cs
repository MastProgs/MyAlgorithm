using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace TestWPF
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class HelloWPF : Window
    {
        public HelloWPF()
        {
            InitializeComponent();
            LogMonitor = "Hello WPF";
        }

        public string LogMonitor { get; set; }

        private void OnOptionChecked()
        {
            if (opt1.IsChecked == true)
            {
                logMonitor.Text += " + Option Checked";
            }
        }

        private void okBtn_Click(object sender, RoutedEventArgs e)
        {
            logMonitor.Text = "Ok Button Clicked";
            OnOptionChecked();
        }

        private void cancelBtn_Click(object sender, RoutedEventArgs e)
        {
            logMonitor.Text = "Cancel Button Clicked";
            OnOptionChecked();
        }

        private void opt1_Checked(object sender, RoutedEventArgs e)
        {
            logMonitor.Text = "Option Checked";
        }

        private void newWindow_Click(object sender, RoutedEventArgs e)
        {
            AdditionalWindow newWindow = new AdditionalWindow();
            newWindow.Show();
            logMonitor.Text = "AdditionalWindow Activated";
        }
    }
}
