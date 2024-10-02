# Controlador de Energía con Arduino para Protección de Baterías AGM

Este repositorio contiene el código para un **controlador de energía** diseñado para proteger un banco de baterías **AGM de plomo Troyan** dentro de un sistema de energía eólica que actúa como una simulación de la red eléctrica. El controlador se asegura de que las baterías AGM no se descarguen por debajo de los **48V** y las protege de un mayor deterioro. Este sistema es crítico, ya que estas baterías están desgastadas y se cargan y descargan rápidamente.

## Descripción del Proyecto

El sistema de energía incluye **dos bancos de baterías**:
1. **Banco 1**: Baterías **AGM de plomo Troyan** que están desgastadas y requieren protección para evitar que su voltaje caiga por debajo de **48V**.
2. **Banco 2**: Nuevo banco de **baterías de 150 amperios**, que funcionan perfectamente y no requieren supervisión constante.

El **sistema eólico** simula la red eléctrica y alimenta ambos bancos. Sin embargo, el controlador está específicamente diseñado para monitorear el banco de baterías AGM y evitar que se descarguen por debajo de los **48V**, lo que podría dañarlas irreversiblemente. Si el voltaje de las baterías AGM supera los **52V**, el controlador permite el paso de corriente nuevamente.

### Contexto

Este controlador fue diseñado para una **estancia rural** aislada, ubicada a más de 100 km de la civilización, donde no hay acceso a la red eléctrica. El sistema de energía eólica simula la red eléctrica y el controlador juega un rol fundamental en proteger las baterías desgastadas.

### Hardware Utilizado

- **Arduino**: El microcontrolador que supervisa los voltajes y controla el paso de corriente.
- **Relé de Arduino**: Controla el flujo de corriente hacia el banco de baterías AGM.
- **Contactor**: Utilizado para manejar corrientes más altas que el relé.
- **Resistencias (divisor de tensión)**: Utilizadas para medir el voltaje de las baterías AGM.
  - `R1 = 100000Ω`
  - `R2 = 10000Ω`

## Funcionalidad del Código

El código del Arduino monitorea continuamente el voltaje de las baterías AGM y regula el flujo de corriente según las siguientes condiciones:

1. **Voltaje > 52V**: El sistema permite que la corriente fluya hacia las baterías AGM.
2. **Voltaje < 48V**: El sistema corta el paso de corriente para proteger las baterías de una descarga profunda.
3. **Filtro de Media Móvil**: Se utiliza un filtro para calcular un promedio de las lecturas de voltaje, lo que permite obtener una medición más estable y precisa.

## Proceso de Fabricación

### 1. Medición del Voltaje

El sistema usa un **divisor de tensión** con resistencias para medir el voltaje de las baterías AGM y convertirlo en un valor legible para el Arduino. El código implementa un filtro de media móvil para promediar las lecturas y obtener una medida más precisa del voltaje de las baterías.

### 2. Control del Relé

El relé es controlado por el Arduino de la siguiente manera:
- Si el voltaje supera los **52V**, el relé se activa y la corriente vuelve a fluir hacia las baterías AGM.
- Si el voltaje cae por debajo de **48V**, el relé se desactiva y corta el flujo de corriente, protegiendo las baterías.

### 3. Animación de LEDs

El sistema también incluye una animación visual de **LEDs** para mostrar si el relé está activado o desactivado, proporcionando una indicación clara del estado del sistema.

## Imágenes del Proyecto

Aquí se incluyen imágenes del sistema montado y del circuito de control.

![Vista del controlador](ruta/a/imagen_controlador.jpg)
![Diagrama del circuito](ruta/a/diagrama_circuito.jpg)

## Cómo Usar Este Repositorio

1. **Cloná este repositorio** en tu computadora.
2. **Subí el código al Arduino** utilizando el **Arduino IDE**.
3. **Configura las conexiones eléctricas** de acuerdo con el diagrama del circuito.
4. **Prueba el sistema** conectándolo al conjunto de baterías AGM y monitorea cómo regula el flujo de corriente según el voltaje.

## Contribuciones

Si querés mejorar el proyecto o tenés ideas para optimizarlo, sos más que bienvenido a enviar un **pull request** o abrir un **issue**.

---

Desarrollado por **Mateo Rodriguez**.

