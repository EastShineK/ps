package login;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class LoginFrame extends JFrame{

  String id = "admin";
  String password = "1234qwer";
  JTextField idField= new JTextField(10);
  JPasswordField pwField= new JPasswordField(10);
  
  public LoginFrame(){
     setTitle("Login");
     setResizable(false);
     setDefaultCloseOperation(EXIT_ON_CLOSE);
     setLayout(new GridLayout(3,1));
     // implement your code
     JPanel panel_1 = new JPanel();
     JPanel panel_2 = new JPanel();
     JPanel panel_3 = new JPanel();
     
     JLabel label = new JLabel("ID");
     JLabel pswrd = new JLabel("Password");
     JButton logButton = new JButton("login");
     
     label.setPreferredSize(new Dimension(80,10));
     pswrd.setPreferredSize(new Dimension(80,10));
     logButton.setPreferredSize(new Dimension(80,10));
     
     panel_1.add(label);
     panel_1.add(idField);
     panel_2.add(pswrd);
     panel_2.add(pwField);
     add(logButton);
     
     logButton.addActionListener(new ActionListener(){
        public void actionPerformed (ActionEvent e) {
           String tempId = idField.getText();
           String tempPassword = pwField.getText();
           
           if(tempId.equals(id)&&tempPassword.contentEquals(password)) {
              JOptionPane.showMessageDialog(null,"Success");
           }
           else {
              JOptionPane.showMessageDialog(null, "Fail");
           }
       }
    });
     
     Container c = getContentPane();
     c.add(panel_1);
     c.add(panel_2);
     c.add(logButton);
     setSize(300,125);
     
     
     setVisible(true);
  }
  public static void main(String[] args) {LoginFrame frame = new LoginFrame();}

}
