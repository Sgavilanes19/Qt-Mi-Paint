#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow> //Para que la clase herede
#include <QImage>  //Imagen
#include <QPainter>
#include <QMouseEvent> // Eventos del mouse
#include <QPaintEvent> //Pintando
#include <QDebug>
#include <QInputDialog> //Cuadros de dialogo predeterminados
#include <QColorDialog>
#include <QFileDialog> //Guardar el archivo
#include <QMessageBox>
#include <QToolBar>
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;  //override (sobre-escrbir)
    void mousePressEvent(QMouseEvent *event) override;   //click
    void mouseMoveEvent(QMouseEvent *event) override;    //mover
    void mouseReleaseEvent(QMouseEvent *event) override; //sueltas el mouse



private slots:
    void on_actionAncho_triggered();

    void on_actionSalir_triggered();

    void on_actionColor_triggered();

    void on_actionNuevo_triggered();

    void on_actionGuardar_triggered();

    void on_actionLineas_triggered();

private:
    Ui::Principal *ui;
    QImage *mImagen;        // Imagen sobre la que se va a dibujar
    QPainter *mPainter;     // Painter de la imagen
    QPoint mInicial;        // Punto incial para dibujar la línea
    QPoint mFinal;          // Punto final para dibujar la línea
    bool mPuedeDibujar;     // Determina si debe o no dibujar
    int mAncho;             // Define el ancho del pincel
    QColor mColor;          // Define el color del pincel
    int mNumLineas;         // Cuenta el número de líneas
};
#endif // PRINCIPAL_H
