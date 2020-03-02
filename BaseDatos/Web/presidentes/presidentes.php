<?php
	include"config.php";
	require_once "HTML/Template/ITX.php";

	// ========================================================================
	//
	// 	Cargamos el template principal
	//
	// ========================================================================
	$template = new HTML_Template_ITX('./templates');
	$template->loadTemplatefile("principal.html", true, true);

	// Se dio clic en el boton, desplegamos a los presidentes
	if($_GET['entrar']){
		// Nos conectamos a la base de datos
	  	$link = mysql_pconnect($cfgServer['host'], $cfgServer['user'], $cfgServer['password']) or die("Could not connect to MySQL database");

	  	mysql_select_db($cfgServer['dbname']) or die("Could not select database");

	  	$query = "SELECT nombre, ap_paterno, ap_materno, ciudad, estado, nacimiento, muerte FROM presidentes";

		// ========================================================================
		//
		// 	Cargamos el template de la tabla con los presidentes
		//
		// ========================================================================
		$template->setVariable("TITULO", "Presidentes de Mexico");
		$template->addBlockfile("CONTENIDO", "PRESIDENTES", "tabla.html");

		$template->setCurrentBlock("PRESIDENTES");
		$template->setVariable("MENSAJE_BIENVENIDA", "Hola Usuario");

		// Ejecutamos el query
		$result = mysql_query($query) or die("Query 1 failed");

		 while($line = mysql_fetch_assoc($result)){

		 	if($line['muerte'] == NULL){
		 		$muerte = '--';
		 	}
		 	else{
		 		$muerte = $line['muerte'];
		 	}

		 	// Fijamos el bloque con la informacion de cada presidente
		 	$template->setCurrentBlock("PRESIDENTE");

		 	// Desplegamos la informacion de cada presidentes
			$template->setVariable("NOMBRE", $line['nombre']);
			$template->setVariable("AP_PATERNO", $line['ap_paterno']);
			$template->setVariable("AP_MATERNO", $line['ap_materno']);
			$template->setVariable("CIUDAD", $line['ciudad']);
			$template->setVariable("ESTADO", $line['estado']);
			$template->setVariable("NACIMIENTO", $line['nacimiento']);
			$template->setVariable("MUERTE", $muerte);

			$template->parseCurrentBlock();
		 }// while


		$template->parseCurrentBlock("PRESIDENTES");
		// Liberamos memoria
	 	mysql_free_result($result);

	 	// Cerramos la conexion
		mysql_close($link);
	}
	else{
		// ========================================================================
		//
		// 	Cargamos el template de la pagina inicial
		//
		// ========================================================================
		$template->setVariable("TITULO", "Presidentes");
		$template->addBlockfile("CONTENIDO", "INICIO", "inicio.html");

		//$template->setCurrentBlock("INICIO");
		//$template->setVariable("VARIABLE", "variable de prueba");
		//$template->parseCurrentBlock();
		$template->touchBlock('INICIO');
	}

	// Mostramos la pagina con los templates que llenamos
	$template->show();
?>
