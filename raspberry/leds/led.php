<html>
<head><title>Ejecutar Archivo</title></head>
<body>
<form name="Mi Formulario" action="led.php" method="post">
<input type="submit" value="Encender el led 17" name="boton">
<input type="submit" value="Apagar el led 17" name="boton2">
</form>
<?php
// Aca controlas si el usuario hace click en el boton
if(isset($_POST['boton']))
{

 echo exec('sudo python /var/www/leds/encenderled.py');
}

if(isset($_POST['boton2']))
{
 echo exec('sudo python /var/www/leds/apagarled.py');
}

?>
</body>
</html>

