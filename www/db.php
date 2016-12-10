<?php
  include("template/header.php");
?>

    <nav class="navbar navbar-static-top navbar-dark bg-inverse">
      <div class="container">
        <a class="navbar-brand" href="index.php">SIFT</a>
        <ul class="nav navbar-nav">
          <li class="nav-item">
            <a class="nav-link" href="index.php">Hlavní stránka</a>
          </li>
          <li class="nav-item active">
            <a class="nav-link" href="db.php">Databáze obrázků</a>
          </li>
        </ul>
      </div>
    </nav>

    <div class="main">
      <div class="container img-db">
        <h1>Image retrieval - podobnost obrázků (SIFT)</h1>
        <div class="row">
          <div class="col-md-4">
            <img src="img/img-01.png" alt="img" class="img-fluid">
          </div>
          <div class="col-md-4">
            <img src="img/img-02.png" alt="img" class="img-fluid">
          </div>
          <div class="col-md-4">
            <img src="img/img-03.png" alt="img" class="img-fluid">
          </div>
        </div>
        <div class="row">
          <div class="col-md-4">
            <img src="img/img-04.png" alt="img" class="img-fluid">
          </div>
          <div class="col-md-4">
            <img src="img/img-05.png" alt="img" class="img-fluid">
          </div>
          <div class="col-md-4">
            <img src="img/img-06.png" alt="img" class="img-fluid">
          </div>
        </div>
        <div class="row">
          <div class="col-md-4">
            <img src="img/img-07.png" alt="img" class="img-fluid">
          </div>
          <div class="col-md-4">
            <img src="img/img-08.png" alt="img" class="img-fluid">
          </div>
          <div class="col-md-4">
            <img src="img/img-09.png" alt="img" class="img-fluid">
          </div>
        </div>
        <div class="row">
        </div>
    </div>
  </div>

<?php
  include("template/footer.php");
?>