<?php

$host = "172.16.63.111";
$user = "afontraille";
$password = "dTj124fs";
$db = "dbafontrailleNewWorld";

$connect=mysql_connect($host, $user, $password) or die(mysql_error());

mysql_select_db($db, $connect);

$sql="Select emailUser from utilisateur";

$req=mysqli_query($sql)

while($data = mysql_fetch_assoc($req))
{
	
$to = $data;
$subject = "TestNW";
$headers  = "From: newWorld@btsinfogap.org\n";

	$sql2="Select"

	if($message="C'est un test";

//$headers  = 'MIME-Version: 1.0' . "\r\n";
//$headers .= 'Content-type: text/html; charset=UTF-8' . "\r\n";

$result = mail($to, $subject, $message, $headers);

if( $result == true )
  {
      echo 'l\'email a bien été envoyé';
  }
  else
  {
      echo 'l\'email n\'a pas pu être envoyé !';
  }

?>
