import java.awt.*;
import java.awt.event.*;
import java.net.*;
import java.io.*;

public class HostNameToAddress {
    TextField inputText;
    TextArea output;

    public static void main(String[] args) {
        new HostNameToAddress().work();
    }

    public void work() {
        Frame f = new Frame("HostNameToAddress");
        output = new TextArea();
        inputText = new TextField("<Type Host Name here>");
        inputText.addActionListener(new AddressListener());
        f.add(output, "Center");
        f.add(inputText, "South");
        f.setSize(400, 300);
        f.setVisible(true);

        try {
            InetAddress inetAddress = InetAddress.getLocalHost();
            output.append("\nYour Host Name is: " + inetAddress.getHostName());
            output.append("\nYour Host IP Address is: " + inetAddress.getHostAddress());
        }
        catch (UnknownHostException error) {
            output.append("\nError in getLocalHost()\n");
        }
    }

    class AddressListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            String h_name =inputText.getText();
            try {
                InetAddress inetAddress = InetAddress.getByName(h_name);
                output.append("\n\nFor the Host: " + inetAddress.getHostName());
                output.append("\n IP Address is: " + inetAddress.getHostAddress());
            }
            catch (UnknownHostException error) {
                output.append("\nFailed to find: " + h_name);
            }
        }
    }
}


