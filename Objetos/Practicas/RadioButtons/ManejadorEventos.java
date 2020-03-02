import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.awt.*;

public class ManejadorEventos implements ActionListener{
  static double[] arreglo=new double[3];
  public void actionPerformed(ActionEvent evento){
    JLabel limsup=new JLabel("Ingrese el limite superior:");
    JLabel liminf=new JLabel("Ingrese el limite inferior:");
    JLabel puntoev=new JLabel("Ingrese el punto a evaluar:");
    JLabel min=new JLabel("Ingrese el punto min a evaluar:");
    JLabel max=new JLabel("Ingrese el punto max a evaluar:");
    JPanel pan=new JPanel();
    Respuestas obj=new Respuestas();
    if(evento.getSource()== Radio.aplicar){
      try{
        String buscar="X2";
        String formu=VentanaP.formulaGUI.getText();
        boolean i=formu.contains(buscar);
        if(i==false)
          throw new Exception ();
        int pos=formu.indexOf("X2");
        String[] Arrstr=formu.split("X2");
        if(pos==0)
          arreglo[2]=1;
        else
          arreglo[2]=Integer.parseInt(Arrstr[0]);
        pos=Arrstr[1].indexOf('X');
        if(pos!=1){
          arreglo[1]=Integer.parseInt(Arrstr[1].substring(0,pos));
          arreglo[0]=Integer.parseInt(Arrstr[1].substring(pos+1));
        }
        else{
          if(Arrstr[1].indexOf('-')==0)
            arreglo[1]=-1;
          else
            arreglo[1]=1;
          arreglo[0]=Integer.parseInt(Arrstr[1].substring(2));
        }
        if(Radio.integral.isSelected()){
          VentanaP.panelRespuesta.updateUI();
          VentanaP.panelRespuesta.repaint();
          VentanaP.panelRespuesta.removeAll();
          pan.add(limsup);
          pan.add(VentanaP.texto1);
          pan.add(liminf);
          pan.add(VentanaP.texto2);
          pan.add(VentanaP.calcula);
          VentanaP.panelRespuesta.add(pan);
        }
        else if(Radio.punto.isSelected()){
          VentanaP.panelRespuesta.updateUI();
          VentanaP.panelRespuesta.repaint();
          VentanaP.panelRespuesta.removeAll();
          pan.add(puntoev);
          pan.add(VentanaP.texto1);
          pan.add(VentanaP.calcula1);
          VentanaP.panelRespuesta.add(pan);
        }
        else if(Radio.parametros.isSelected()){
          VentanaP.panelRespuesta.updateUI();
          VentanaP.panelRespuesta.repaint();
          VentanaP.panelRespuesta.removeAll();
          pan.add(min);
          pan.add(VentanaP.texto1);
          pan.add(max);
          pan.add(VentanaP.texto2);
          pan.add(VentanaP.calcula2);
          VentanaP.panelRespuesta.add(pan);
        }
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Formato: AX2+BX+C","Error", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(evento.getSource()==VentanaP.calcula){
      try{
        int limitesup=Integer.parseInt(VentanaP.texto1.getText().toString());
        int limiteinf=Integer.parseInt(VentanaP.texto2.getText().toString());
        if(limitesup<=limiteinf)
          throw new Exception();
        JLabel res=new JLabel("La integral es: "+obj.Integral(arreglo,limiteinf,limitesup));
        VentanaP.panelRespuesta.updateUI();
        VentanaP.panelRespuesta.repaint();
        VentanaP.panelRespuesta.remove(VentanaP.panelRespuesta1);
        VentanaP.panelRespuesta1.removeAll();
        VentanaP.panelRespuesta.add(VentanaP.panelRespuesta1);
        VentanaP.panelRespuesta1.add(res);
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Favor de ingresar solo numeros en los parametros y el limite superior tiene que ser mas grande","Error", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(evento.getSource()==VentanaP.calcula1){
      try{
        int x=Integer.parseInt(VentanaP.texto1.getText().toString());
        JLabel res=new JLabel("La formula evualuada en "+x+" es: "+obj.Unpunto(arreglo,x));
        VentanaP.panelRespuesta.updateUI();
        VentanaP.panelRespuesta.repaint();
        VentanaP.panelRespuesta.remove(VentanaP.panelRespuesta1);
        VentanaP.panelRespuesta1.removeAll();
        VentanaP.panelRespuesta.add(VentanaP.panelRespuesta1);
        VentanaP.panelRespuesta1.add(res);
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Favor de ingresar solo numeros en los parametros","Error", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(evento.getSource()==VentanaP.calcula2){
      try{
        int limitesup=Integer.parseInt(VentanaP.texto2.getText().toString());
        int limiteinf=Integer.parseInt(VentanaP.texto1.getText().toString());
        int temp=0;
        if(limitesup<=limiteinf)
          throw new Exception();
        if(limitesup>=0&&limiteinf>=0)
          temp=limitesup-limiteinf;
        else if(limitesup<0&&limiteinf<0)
          temp=Math.abs(limitesup)-Math.abs(limiteinf);
        else
          temp=Math.abs(limitesup)+Math.abs(limiteinf);
        temp=Math.abs(temp)+1;
        VentanaP.datos=new String[temp][2];
        double suma=0;
        for(int fila=0;fila<=temp-1;fila++){
          suma=0;
          VentanaP.datos[fila][0]=String.valueOf(limiteinf);
          for(int i=arreglo.length-1;i>=0;i--)
            suma+=arreglo[i]*Math.pow(limiteinf,i);
          VentanaP.datos[fila][1]=String.valueOf(suma);
          limiteinf++;
        }
        VentanaP.panelRespuesta.updateUI();
        VentanaP.panelRespuesta.repaint();
        VentanaP.panelRespuesta.remove(VentanaP.panelRespuesta1);
        VentanaP.panelRespuesta1.removeAll();
        VentanaP.panelRespuesta1.setLayout(new BorderLayout());
        VentanaP.panelRespuesta.add(VentanaP.panelRespuesta1);
        VentanaP.tabla=new JTable(VentanaP.datos,VentanaP.nombres);
        VentanaP.panelRespuesta1.add(VentanaP.tabla);
        JScrollPane tableContainer=new JScrollPane(VentanaP.tabla);
        VentanaP.panelRespuesta1.add(tableContainer);
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Favor de ingresar solo numeros en los parametros y el numero maximo tiene que ser mas grande","Error", JOptionPane.ERROR_MESSAGE);
      }
    }
  }
}
