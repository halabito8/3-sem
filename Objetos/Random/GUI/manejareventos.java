import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

public class ManejarEventos implements ActionListener
{
  public void actionPerformed(ActionEvent Evento)
  {
    if(Evento.getSource() == PanelCuadradoDatos.Area)
    {
      try
      {
        int ResArea = Integer.parseInt(PanelCuadradoDatos.Lado.getText().substring(0,1));
        double ResFinalArea = Math.pow((double)ResArea,2);
        PanelCuadradoRes.Resultado.setText("El area es: "+Double.toString(ResFinalArea));
      }catch(Exception e)
      {
        JOptionPane.showMessageDialog(null,"Introducir sólo números: " +
        PanelCuadradoDatos.Lado.getText().toString(),"Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    else if(Evento.getSource() == PanelCuadradoDatos.Volumen)
    {
      try
      {
        int ResVolumen = Integer.parseInt(PanelCuadradoDatos.Lado.getText().substring(0,1));
        double ResFinalVolumen = Math.pow((double)ResVolumen,3);
        PanelCuadradoRes.Resultado.setText("El volumen es: "+Double.toString(ResFinalVolumen));
      }catch(Exception e)
      {
        JOptionPane.showMessageDialog(null,"Introducir sólo números: " +
        PanelCuadradoDatos.Lado.getText().toString(),"Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    else if(Evento.getSource() == PanelTrianguloDatos.Area)
    {
      try
      {
        int ResArea = Integer.parseInt(PanelTrianguloDatos.Base.getText().substring(0,1));
        int ResArea2 = Integer.parseInt(PanelTrianguloDatos.Altura.getText().substring(0,1));
        double ResFinalArea = (double)(ResArea*ResArea2/2);
        PanelTrianguloRes.Resultado.setText("El area es: "+Double.toString(ResFinalArea));
      }catch(Exception e)
      {
        JOptionPane.showMessageDialog(null,"Introducir sólo números / Campo Vacío: ","Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    else if(Evento.getSource() == PanelTrianguloDatos.Volumen)
    {
      try
      {
        int ResVolumen = Integer.parseInt(PanelTrianguloDatos.Base.getText().substring(0,1));
        int ResVolumen2 = Integer.parseInt(PanelTrianguloDatos.Altura.getText().substring(0,1));
        double ResFinalVolumen = (double)(ResVolumen*ResVolumen2/3);
        PanelTrianguloRes.Resultado.setText("El volumen es: "+Double.toString(ResFinalVolumen));
      }catch(Exception e)
      {
        JOptionPane.showMessageDialog(null,"Introducir sólo números / Campo Vacío: ","Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    else if(Evento.getSource() == PanelRectanguloDatos.Area)
    {
      try
      {
        int ResArea = Integer.parseInt(PanelRectanguloDatos.Base.getText().substring(0,1));
        int ResArea2 = Integer.parseInt(PanelRectanguloDatos.Altura.getText().substring(0,1));
        double ResFinalArea = (double)(ResArea*ResArea2);
        PanelRectanguloRes.Resultado.setText("El area es: "+Double.toString(ResFinalArea));
      }catch(Exception e)
      {
        JOptionPane.showMessageDialog(null,"Introducir sólo números / Campo Vacío: ","Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    else if(Evento.getSource() == PanelRectanguloDatos.Volumen)
    {
      try
      {
        int ResVolumen1 = Integer.parseInt(PanelRectanguloDatos.Base.getText().substring(0,1));
        int ResVolumen2 = Integer.parseInt(PanelRectanguloDatos.Altura.getText().substring(0,1));
        int ResVolumen3 = Integer.parseInt(PanelRectanguloDatos.Profundidad.getText().substring(0,1));
        double ResFinalVolumen = (double)(ResVolumen1*ResVolumen2*ResVolumen3);
        PanelRectanguloRes.Resultado.setText("El volumen es: "+Double.toString(ResFinalVolumen));
      }catch(Exception e)
      {
        JOptionPane.showMessageDialog(null,"Introducir sólo números / Campo Vacío: ","Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
  }
}
