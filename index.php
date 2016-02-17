<?php session_start(); $_SESSION["id"] = uniqid(); ?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta name="description" content="Single file autograder with significant tolerance">
  <meta name="author" content="Afrizal Fikri">

  <title>PTI Grader Site</title>
  <link rel="icon" href="favicon.ico" type="image/x-icon"/>

  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" type="text/css">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css" type="text/css">
  <link rel="stylesheet" href="css/custom.css">
  
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
  <script type="text/javascript" src="js/ajaxupload.js" charset="utf-8"></script>
  <script type="text/javascript" src="js/apps.js" charset="utf-8"></script>
  <script type="text/javascript" src="js/smoothscroll.js" charset="utf-8"></script>
</head>

<body id="page-top" ng-app="pti-grader">
  <nav id="mainNav" class="navbar navbar-default navbar-fixed-top">
    <div class="container-fluid">
      <!-- Brand and toggle get grouped for better mobile display -->
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
          <span class="sr-only">Toggle navigation</span>
        </button>
        <a class="navbar-brand page-scroll" href="#page-top">PTI Grader</a>
      </div>

      <!-- Collect the nav links, forms, and other content for toggling -->
      <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
        <ul class="nav navbar-nav navbar-right">
          <li>
            <a class="page-scroll" href="#getting-started">Getting Started</a>
          </li>
          <li>
            <a class="page-scroll" href="#grade">Grade Now</a>
          </li>
          <li>
            <a class="page-scroll" href="#contact">Contact Me</a>
          </li>
        </ul>
      </div>
      <!-- /.navbar-collapse -->
    </div>
    <!-- /.container-fluid -->
  </nav>

  <section id="getting-started">
    <div class="container" id="container-getting-started">
      <h1>Getting Started</h1>
      If you have understood how PTI Grader works, skip to <a href="#grade">grade</a> section
    </div>
  </section>

  <section id="grade" ng-controller="gradeCtrl">
    <div class="container" id="container-grade">
      <h1>Grade Now</h1>
      <form id="ajax-grade" method="post" action="upload.php" enctype="multipart/form-data">
        <div class="case">
          Case #1
          <div>
            <div class="col-md-5 block">
              <textarea name="input-case-1" id="input-case-1" placeholder="Input case #1" required></textarea>
            </div>
            <div class="col-md-2 block"></div>
            <div class="col-md-5 block">
              <textarea name="output-case-1" id="output-case-1" placeholder="Output case #1" required></textarea>
            </div>
          </div>
        </div>

        <button class="btn btn-primary" type="button" onclick="addCase()">Add case</button>

        <input class="hiddenfiles" type="file" name="fileToUpload" id="fileToUpload" onchange="upload()">
        <br>
        <button class="btn btn-primary" type="button" id="triggerUpload" onclick="triggerFile()">Add file</button> <span id="uploadStatus"></span>
        <br><br>
        <button class="btn btn-primary" type="submit" onclick="Grade()">Grade</button>
      </form>

    <div id="grading-messages"></div>
    </div>
  </section>

  <section id="contact">
  <div class="container" id="container-contact">
    <h1>Any problem? Contact me here</h1>
    <form id="ajax-contact" method="post" action="mailer.php">
      <input class="field transparent" type="text" id="name" name="name" placeholder="Name" required>

      <input class="field transparent" type="email" id="email" name="email" placeholder="Email" required>

      <textarea class="field transparent" id="message" name="message" placeholder="Message" required></textarea>
      <br>
      <br>
      <button class="btn btn-primary" type="submit">Send</button>
    </form>

    <div id="contact-messages"></div>
  </div>
  </section>

  <footer class="footer">
    <div class="container">
      <p class="text-muted">2015 © Copyright <a href="http://icalicul.me">Afrizal Fikri</a></p>
    </div>
  </footer>
</body>
</html>

