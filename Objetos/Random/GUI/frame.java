import java.awt.GridLayout;
import javax.swing.JFrame;

public class Frame extends JFrame
{
  public Frame()
  {
    super("Cálculo de Áreas y Volúmenes");
    setSize(700,500);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setResizable(false);
    setLayout(new GridLayout(3,3));
    PanelCuadradoImg ImgCuadrado = new PanelCuadradoImg();
    PanelCuadradoDatos DatosCuadrado = new PanelCuadradoDatos();
    PanelCuadradoRes ResCuadrado = new PanelCuadradoRes();
    this.add(ImgCuadrado);
    this.add(DatosCuadrado);
    this.add(ResCuadrado);
    ManejarEventos Eventos = new ManejarEventos();
    PanelCuadradoDatos.Area.addActionListener(Eventos);
    PanelCuadradoDatos.Volumen.addActionListener(Eventos);
    PanelTrianguloImg ImgTriangulo = new PanelTrianguloImg();
    PanelTrianguloDatos DatosTriangulo = new PanelTrianguloDatos();
    PanelTrianguloRes ResTriangulo = new PanelTrianguloRes();
    PanelTrianguloDatos.Area.addActionListener(Eventos);
    PanelTrianguloDatos.Volumen.addActionListener(Eventos);
    this.add(ImgTriangulo);
    this.add(DatosTriangulo);
    this.add(ResTriangulo);
    PanelRectanguloImg ImgRectangulo = new PanelRectanguloImg();
    PanelRectanguloDatos DatosRectangulo = new PanelRectanguloDatos();
    PanelRectanguloRes ResRectangulo = new PanelRectanguloRes();
    PanelRectanguloDatos.Area.addActionListener(Eventos);
    PanelRectanguloDatos.Volumen.addActionListener(Eventos);
    this.add(ImgRectangulo);
    this.add(DatosRectangulo);
    this.add(ResRectangulo);
  }
}
