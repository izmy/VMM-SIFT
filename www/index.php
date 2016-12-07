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

          if( !isset( $_FILES['photo']['name'] ) ) {
            include("template/form-upload.php");
          } else {
            if($_FILES['photo']['name'])
            {
              //if no errors...
              if(!$_FILES['photo']['error'])
              {
                if($_FILES['photo']['size'] > (10240000)) //can't be larger than 10 MB
                {
                  $valid_file = false;
                  $message = 'Oops!  Soubor je příliš velký.';
                }
                else {
                  $valid_file = true;
                }
                
                //if the file has passed the test
                if($valid_file)
                {
                  //move it to where we want it to be
                  $currentdir = getcwd();

                  $filename_extension = basename($_FILES['photo']['name']); //etc. img01.png
                  $exploded_filepath = explode(".", $filename_extension);
                  $extension = end($exploded_filepath); //etc. png
                  $filename = basename($filename_extension, ".".$extension); //etc. img01

                  $target = $currentdir .'/uploads/' . $filename_extension;
                  move_uploaded_file($_FILES['photo']['tmp_name'], $target);
                  $message = 'Obrázek <strong>'. $filename_extension .'</strong> byl úspěšně nahrán.';
                }
              }
              //if there is an error...
              else
              {
                //set that to be the returned message
                $message = 'Ooops! Nastala chyba:  '.$_FILES['photo']['error'];
              }
            } else {
              $message = "Nebyl vybrán obrázek.";
            }

            echo '<h2>'.$message.'</h2>';
            if($valid_file) {
              echo '<img src="uploads/'.basename($_FILES['photo']['name']).'" alt="img" class="img-fluid"><br>';
              ?>

              <form action="find-image.php" method="post">
                <input type="hidden" name="filename" value='<?php echo $filename; ?>'>
                <p><input type="submit" name="submit" value="Najít podobný obrázek" class="btn btn-primary btn-lg" /></p>
              </form>
              <?php
            }
          }

        ?>
        
      </div>
    </div>

<?php
  include("template/footer.php");
?>