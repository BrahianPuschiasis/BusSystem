# Propuesta de Aplicación para Gestión de Pasajes de Ómnibus

Desarrollar una aplicación utilizando el lenguaje de programación C, que permita la gestión de pasajes de ómnibus para una empresa de transporte de pasajeros. Esta empresa realiza viajes nacionales a diferentes puntos del país.

## Requisitos de la Aplicación

La aplicación deberá administrar los siguientes componentes:
- Recorridos
- Ómnibus
- Viajes
- Pasajes (ventas y reservas)

### Directivas

El diseño de pantallas, menús y submenús es totalmente a elección del programador, así como también el nombre que desee darle a la aplicación.

### Información de Recorridos

De cada recorrido se conoce:
- Origen
- Destino
- Paradas intermedias (si las tiene)
- Duración aproximada
- Precio

### Información de Viajes

Al crear un nuevo viaje se debe indicar la siguiente información:
- Fecha y hora
- Ómnibus
- Recorrido
- Tipo (directo, semi-directo o común)
- Chofer
- Guarda

### Información de Ómnibus

Cada ómnibus de la empresa se identifica con un número y posee una cantidad fija de asientos.

### Información de Pasajes

Los pasajes pueden ser al destino del viaje o a paradas intermedias. En este caso, el precio varía y se calcula a partir de la cantidad de kilómetros recorridos.

### Reservas de Pasajes

Las reservas de los pasajes tienen validez hasta 30 minutos antes de la partida del viaje. Si no se confirma una reserva, se anula y el o los asientos vuelven a estar disponibles.

### Pantalla de Venta de Pasajes

En la pantalla de venta de pasajes debe desplegarse:
- Asientos libres
- Asientos disponibles, indicando cuáles son ventanilla y cuáles pasillo

## Consultas

La aplicación debe permitir realizar las siguientes consultas:
- Desplegar los horarios de los viajes creados para un recorrido particular.
- Desplegar los viajes que tengan asientos libres (indicando cantidad y horario) para un recorrido particular.
- Desplegar los datos de los ómnibus disponibles para realizar un viaje determinado.
- Desplegar todos los viajes realizados por un chofer o por un guarda. Ordenar el listado por fecha.

## Listados

La aplicación debe generar los siguientes listados:
- Todos los viajes realizados. Ordenar el listado por fecha.
- Todos los recorridos con sus paradas intermedias.

## Almacenamiento de Información

Se deberá utilizar archivos binarios para guardar la información.

## Estructuras Dinámicas de Datos

En la construcción se deberá utilizar al menos una estructura dinámica de datos.
