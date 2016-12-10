<?php
  include("template/header.php");
?>

    <nav class="navbar navbar-static-top navbar-dark bg-inverse">
      <div class="container">
        <a class="navbar-brand" href="index.php">SIFT</a>
        <ul class="nav navbar-nav">
          <li class="nav-item">
            <a class="nav-link active" href="index.php">Hlavní stránka</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="db.php">Databáze obrázků</a>
          </li>
        </ul>
      </div>
    </nav>

    <div class="main">
      <div class="container img-result">
        <h1>Image retrieval - podobnost obrázků (SIFT)</h1>
        <?php

          if( isset($_POST['filename']) )
          {
            if ( empty($_POST['filename']) ) {
              echo "<h2>Obrázek nebyl nalezen.</h2>";
            }
            else {
            	$time_pre = microtime(true);

            	// echo './apps/ASIFT ./uploads/'. $_POST['filename'] .'.png ./uploads/'.$_POST['filename'].'.txt 2>&1';
            	// echo "<br>";
            	// echo './apps/Cluster uploads/' . $_POST['filename'] . '.txt uploads/' . $_POST['filename'] . 'c.txt 2>&1';
            	// echo "<br>";
            	// echo './apps/SQFD uploads/' . $_POST['filename'] . 'c.txt db/db.txt 2>&1';
            	
            	// //ASIFT
              //	$out = shell_exec('./apps/ASIFT ./uploads/'. $_POST['filename'] .'.png ./uploads/'.$_POST['filename'].'.txt 2>&1');
              	// for ($i = 0; $i < strlen($out); $i++)
              	// {
               //  	if ( ord($out[$i]) == 10 ) echo "<br>";
               //  	echo $out[$i];
              	// }

             //  	//Cluster
             //  	$out = shell_exec('./apps/Cluster uploads/' . $_POST['filename'] . '.txt uploads/' . $_POST['filename'] . 'c.txt 2>&1');

              	//SQFD
              	$out = shell_exec('./apps/SQFD uploads/' . $_POST['filename'] . 'c.txt db/db.txt 2>&1');
              	$image = preg_split("/[\s+;]/", $out);

              	echo '<h2>Vstupní obrázek</h2>';
              	echo '<img src="uploads/'.$_POST['filename'].'" alt="img" class="img-fluid img-input">';
              	echo '<h2>Podobné obrázky</h2>';
              	echo '<div class="row">';

              	$j = 1;

              	for ($i = 0; $i < count($image); $i ++) { 
              		if ($i % 2 == 0) {
              			echo '<div class="col-md-4">';
	              		echo '<img src="img/' . $image[$i] . '" alt="img" class="img-fluid"><br>';
	              	} else {
	              		echo '<p>Skóre: <strong>' . $image[$i] . '</strong></p>';
	              		echo '</div>';
	              		if ( ($i+1) % 3 == 0 ) {
		              		echo '</div>';
					        echo '<div class="row">';
		              	}
	              	}
              	}
              	echo '</div>';
              	$time_post = microtime(true);
          		$exec_time = round($time_post - $time_pre, 2);
          		echo '<p>Doba výpočtu: <strong>' . $exec_time . 's</strong></p>';
            }
          }
          else {
            include("include-search.php");
          }

        ?>
        
      </div>
    </div>

<?php
  include("template/footer.php");
?>