<?php
  $exponente=_POST['exponente'];
  $numero=_POST['numero'];
  $suma=$numero;
  while(exponente>1){
    $suma=$suma*$numero;
    $exponente--;
  }
  print $suma;
?>
