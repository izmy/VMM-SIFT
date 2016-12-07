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
      <div class="container">
        <h1>Image retrieval - podobnost obrázků (SIFT)</h1>
        <?php

          if( isset($_POST['filename']) )
          {
            if ( empty($_POST['filename']) ) {
              echo "<h2>Obrázek nebyl nalezen.</h2>";
            }
            else {
            	//echo './apps/ASIFT ./uploads/'. $_POST['filename'] .'.png ./uploads/'.$_POST['filename'].'.txt 2>&1';
              	$out = shell_exec('./apps/ASIFT ./uploads/'. $_POST['filename'] .'.png ./uploads/'.$_POST['filename'].'.txt 2>&1');
              	for ($i = 0; $i < strlen($out); $i++)
              	{
                	if ( ord($out[$i]) == 10 ) echo "<br>";
                	echo $out[$i];
              	}
              	$out = shell_exec('./apps/find "' . $_POST['filename'] . '"');
              	
              	for ($i = 0; $i < strlen($out); $i++)
              	{
                	if ( ord($out[$i]) == 10 ) echo "<br>";
                	echo $out[$i];
              	}
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