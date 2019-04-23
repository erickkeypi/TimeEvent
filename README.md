# TimeEvent
Libreria arduino para ejecutar eventos de tiempo

## Cómo usar
Se crea una instancia para cada evento de tiempo que se desee pasando como argumento de la funcion el tiempo de frecuencia en milisegundos que tendrá el evento
```c++
TimeEvent evento = TimeEvent(tiempo);
TimeEvent evento2 = TimeEvent(tiempo2);
TimeEvent evento3 = TimeEvent(tiempo3);
...
...
```
Dentro de `loop` se debe ejecutar la funcion `run`. Esta función devuelve `true` cuando se cumple el tiempo de retraso.
```
void loop() {
  if(evento.run()){
    //Escribir código aqui
  }
}
```
O bien puede ponerse una función como argumento a ser llamada cuando se cumpla el tiempo de retraso. La función a llamar no puede recibir ni retornar ningun valor.
```
void loop() {
  evento.run(funcionAllamar);
}
```
Solo puede utilizarse una de las dos formas.


El evento no comienza a contar por si solo, sino, que hay que llamar a la función `start` para que este empiece a contar.
```
evento.start();
```

Por defecto el evento solo ocurre una vez, pero este comportamiento puede cambiarse para que se repita indefinidamente.

## Funciones
```TimeEvent(unsigned long tiempo)```
Constructor de la clase.

```void setFrecuency(unsigned long frecuencia)```
Cambia la frecuencia a la que se produce el evento.

```boolean run()```
Devuelve `true` cuando se cumple el tiempo de retraso.

```void run(void(fc)(void))```
Ejecuta la función `fc` cuando se cumple el tiempo de retraso.

```unsigned long count()```
Devuelve la cuenta del evento en milisegundos.

```void stop()```
Detiene el evento (La cuenta inicia desde cero si se llama `start` luego de esta función).

```void start()```
Inicia la cuenta

```void pause()```
Detiene la cuenta del evento (La cuenta inicia desde donde estaba cuando se llama `start` luego de esta función).

```void repeat()```
Hace que el evento se repita indefinidamente.

```void noRepeat()```
Hace que el evento solo se ejecute una vez (por defecto).


## License
Copyright (c) 2019 Erick R Garcia Martinez.
Licensed under [Apache license, version2.0](LICENSE).
