# Controlador de Energía con Arduino

Este repositorio contiene el código para un **controlador de energía** que regula el flujo de corriente según el nivel de voltaje de un sistema de **energía eólica** en una zona rural sin acceso a la red eléctrica. El objetivo de este controlador es proteger un conjunto de **baterías de litio** que se descargan y cargan rápidamente debido a su estado de desgaste.

## Descripción del Proyecto

Este proyecto está diseñado para supervisar el voltaje de las baterías del sistema eólico. Si el voltaje de las baterías cae por debajo de **48V**, el sistema corta el paso de corriente, y cuando el voltaje vuelve a superar los **52V**, la corriente vuelve a fluir. Este proceso evita que las baterías se descarguen completamente, protegiendo su ciclo de vida.

### Contexto

El proyecto fue necesario debido a que las baterías del sistema de **energía eólica** están desgastadas, y por lo tanto se cargan y descargan rápidamente. Además, el **inversor principal** está basado en **energía solar**, pero tiene una segunda línea que conecta a la red eléctrica para cargar las baterías. Sin embargo, al estar en una **zona rural remota** (a más de 100 km de la civilización), no hay red eléctrica disponible. Por lo tanto, este sistema de **energía eólica** simula la red eléctrica utilizando este controlador.

### Hardware Utilizado

- **Arduino**: El microcontrolador que regula el paso de la corriente.
- **Relé de Arduino**: Se encarga de abrir o cerrar el circuito de acuerdo al voltaje de las baterías.
- **Contactor**: Permite manejar mayores corrientes que el relé de Arduino.
- **Resistencias**: Utilizadas como divisor de tensión para medir el voltaje de las baterías.
  - `R1 = 100000Ω`
  - `R2 = 10000Ω`

## Funcionalidad del Código

El código tiene las siguientes funciones:

1. **Lectura de voltaje**: Se utiliza un divisor de tensión con dos resistencias para leer el voltaje de las baterías y se aplica un filtro de media móvil para promediar las lecturas.
2. **Control del relé**: 
   - Si el voltaje es mayor o igual a **52V**, el relé se activa y la corriente fluye.
   - Si el voltaje es menor o igual a **48V**, el relé se desactiva y se corta el flujo de corriente.
3. **Visualización y animaciones**: Cuando el relé está activado o desactivado, el código enciende y apaga una serie de LEDs en secuencia para mostrar el estado del sistema.
4. **Protección de las baterías**: El código está diseñado para proteger las baterías de litio del sistema eólico, evitando que se descarguen completamente y preservando su vida útil.

## Diagrama del Circuito

- **Arduino** se conecta a las resistencias que forman el divisor de tensión para leer el voltaje de las baterías.
- El **relé** de Arduino controla un **contactor**, que permite manejar la corriente hacia las baterías.

## Cómo Usar Este Repositorio

1. **Cloná este repositorio** en tu computadora.
2. **Subí el código al Arduino** utilizando el **Arduino IDE**.
3. **Configura las conexiones eléctricas** de acuerdo con el diagrama del circuito.
4. **Prueba el sistema** conectándolo al conjunto de baterías de tu sistema de energía eólica y monitorea cómo regula el flujo de corriente según el voltaje.

## Contribuciones

Si querés mejorar el proyecto o tenés ideas para optimizarlo, sos más que bienvenido a enviar un **pull request** o abrir un **issue**.

---

Desarrollado por **Mateo Rodriguez**.
