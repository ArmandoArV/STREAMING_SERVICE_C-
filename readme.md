# Proyecto servicio de streaming

## Por: Armando Arredondo Valle

## Descripción del proyecto

Este programa simula un servicio de streaming el cual posee 4 clases, en las cuales se aloja la clase padre (Video), la cual aloja los  atributos de nombre, id, género, duración, así como la calificación.

---

## **Puntos a cubrir**

---

|  **Propiedad** | **Archivo (s)** | **Descripción** |
| --- | --- | --- |
| Herencia | - Padre (Video) - Hijos(Movie,Serie,Episodes) | Tenemos como clase padre Video, la cual está heredando los atributos así como una función virtual para impresión a las demás clases, esto con el fin de que se cumpla el concepto básico de herencia.|
| Polimorfismo | main | Se hace uso de los punteros en la parte del main con el fin de que se cumpla el polimorfismo, para el llamado a los métodos. |
|Sobrecarga|main , Usuario.cpp/h | Se hace uso de la sobrecarga para imprimir el nombre de usuario de quien esté utilizando el servicio de streaming.
---

## Uso de la herencia

Hago uso de la herencia para heredar los mismos atributos de Video a las demás clases, esto con el fin de tener un cierto ahorro de trabajo / más escritura de líneas de código.

```c++
class Movie : public Video{
    // Aquí hacemos uso de la herencia de Video a Movie con el fin de tomar las variables públicas en Video
};
```

---

## **Uso del polimorfismo**

---

Utilizamos polimorfismo con el fin de tener métodos diferentes de impresión, tal es el caso de el print que tiene un diverso número de repeticiones a lo largo del documento.

### **.h donde se inicializa el polimorfismo.**

```c++
class Video{
    public:
        virtual void print(); // Aquí tenemos de forma virtual en el .h de video, al nosotros realizar la parte de la herencia en otros archivos podemos utilizar este método de forma personalizada según se adecue a nuestras necesidades.
};
```
