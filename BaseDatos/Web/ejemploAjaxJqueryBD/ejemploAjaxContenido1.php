<?php
	require_once "HTML/Template/ITX.php";
	
	// ========================================================================
	//
	// 	Cargamos el template y desplegamos la pagina 
	// 	del staff
	// 
	// ========================================================================
	$template = new HTML_Template_ITX('./templates');
	$template->loadTemplatefile("./opcion1.html", true, true);
	
	$nombre = $_POST['nombre'];
	$numero = $_POST['numero'];
	
	$template->setVariable("ETIQUETA", "$nombre - $numero");
	
	//$template->setVariable("ETIQUETA", " ");
	
	$template->parseCurrentBlock();
	
	$template->show();
?>
