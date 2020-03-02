import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.BorderLayout;

public class ResCuadrado extends JPanel{
  static JLabel Resul;
  public ResCuadrado(){
    setLayout(new BorderLayout(1,1));
    Resul=new JLabel("");
    this.add(Resul,BorderLayout.CENTER);
  }
}
