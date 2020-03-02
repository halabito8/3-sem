import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

public class ManejadorEventos implements ActionListener{
  public void actionPerformed(ActionEvent Evento){
    if(Evento.getSource()==BotonesCuadrado.Area){
      try{
        int ResArea = Integer.parseInt(BotonesCuadrado.Lado.getText().toString());
        double ResFinalArea = Math.pow((double)ResArea,2);
        ResCuadrado.Resul.setText("El area es: "+Double.toString(ResFinalArea));
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Introducir sólo números: " +
        BotonesCuadrado.Lado.getText().toString(),"Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(Evento.getSource()==BotonesCuadrado.Volumen){
      try{
        int ResArea = Integer.parseInt(BotonesCuadrado.Lado.getText().toString());
        double ResFinalArea = Math.pow((double)ResArea,3);
        ResCuadrado.Resul.setText("El volumen es: "+Double.toString(ResFinalArea));
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Introducir sólo números: " +
        BotonesCuadrado.Lado.getText().toString(),"Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(Evento.getSource()==BotonesTriangulo.Area){
      try{
        int ResArea = Integer.parseInt(BotonesTriangulo.Base.getText().toString());
        int ResArea2 = Integer.parseInt(BotonesTriangulo.Altura.getText().toString());
        double ResFinalArea = (double)(ResArea*ResArea2/2);
        ResTriangulo.Resul.setText("El area es: "+Double.toString(ResFinalArea));
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Introducir sólo números / Campo Vacío: ","Error de Entrada", JOptionPane.ERROR_MESSAGE);

      }
    }
    if(Evento.getSource()==BotonesTriangulo.Volumen){
      try{
        int ResVolumen = Integer.parseInt(BotonesTriangulo.Base.getText().toString());
        int ResVolumen2 = Integer.parseInt(BotonesTriangulo.Altura.getText().toString());
        double ResFinalVolumen = (double)(ResVolumen*ResVolumen2/3);
        ResTriangulo.Resul.setText("El volumen es: "+Double.toString(ResFinalVolumen));
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Introducir sólo números / Campo Vacío: ","Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(Evento.getSource()==BotonesCirculo.Area){
      try{
        int ResArea=Integer.parseInt(BotonesCirculo.Radio.getText().toString());
        double ResFinalArea= Math.PI*Math.pow((double)ResArea,2);
        ResCirculo.Resul.setText("El area es: "+Double.toString(ResFinalArea));
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Introducir sólo números: " +
        BotonesCuadrado.Lado.getText().toString(),"Error de Entrada", JOptionPane.ERROR_MESSAGE);

      }
    }
    if(Evento.getSource()==BotonesCirculo.Volumen){
      try{
        int ResVolumen=Integer.parseInt(BotonesCirculo.Radio.getText().toString());
        double ResFinalVolumen=1.3*(Math.PI*Math.pow((double)ResVolumen,3));
        ResCirculo.Resul.setText("El volumen es: "+Double.toString(ResFinalVolumen));
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Introducir sólo números: " +
        BotonesCuadrado.Lado.getText().toString(),"Error de Entrada", JOptionPane.ERROR_MESSAGE);
      }
    }
  }
}
