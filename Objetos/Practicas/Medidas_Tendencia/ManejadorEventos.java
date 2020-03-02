import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class ManejadorEventos implements ActionListener{
  public void actionPerformed(ActionEvent evento){
    if(evento.getSource()==PIngresarDatos.imprimir){
      try{
        Ventana.panelTable.removeAll();
        int numero1=Integer.parseInt(PIngresarDatos.numvalores.getText().toString());
        Ventana.datos=new String [numero1][2];
        for(int fila=0;fila<Ventana.datos.length;fila++){
          for(int col=0;col<Ventana.datos[0].length;col++)
            Ventana.datos[fila][col]=String.valueOf(fila);
        }
        Ventana.panelTable.updateUI();
        Ventana.panelTable.repaint();
        Ventana.tabla=new JTable(Ventana.datos,Ventana.columnNames);
        JScrollPane tableContainer=new JScrollPane(Ventana.tabla);
        Ventana.panelTable.add(tableContainer);
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Favor de ingresar numeros","Error", JOptionPane.ERROR_MESSAGE);
      }
    }
    if(evento.getSource()==Calcular.calcula){
      try{
        int suma=0;
        double mediana;
        String str;
        for(int fila=0;fila<Ventana.datos.length;fila++)
          suma=suma+Integer.parseInt(Ventana.tabla.getValueAt(fila,1).toString());
        str="El valor de la media es: ";
        mediana=(double)suma/Ventana.datos.length;
        Calcular.medida.setText(str+mediana);
      }catch(Exception e){
        JOptionPane.showMessageDialog(null,"Error","Error", JOptionPane.ERROR_MESSAGE);
      }
    }
  }
}
