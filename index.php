<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta name="description" content="">
  <meta name="author" content="">

  <title>PTI Grader Site</title>

  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" type="text/css">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css" type="text/css">
  <link rel="stylesheet" href="http://cdn.jsdelivr.net/animatecss/2.1.0/animate.min.css" type="text/css">
  <link rel="stylesheet" href="css/custom.css">
</head>
<body id="page-top">
  <nav id="mainNav" class="navbar navbar-default navbar-fixed-top">
    <div class="container-fluid">
      <!-- Brand and toggle get grouped for better mobile display -->
      <div class="navbar-header">
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1">
          <span class="sr-only">Toggle navigation</span>
          <!-- <span class="icon-bar"></span> -->
          <!-- <span class="icon-bar"></span> -->
          <!-- <span class="icon-bar"></span> -->
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
      If you have understand how PTI Grader works, skip to <a href="#grade">grade</a> section
    </div>
  </section>

  <section id="grade">
    <div class="container" id="container-grade">
      <h1>Grade Now</h1>
      <form id="ajax-grade" method="post" action="upload.php" enctype="multipart/form-data">
        <div class="field-control">
          <p>Case #1</p>
          <div class="field">
            <textarea name="input-case-1" id="input-case-1" placeholder="Input case #1" required></textarea>
          </div>
          <div class="field">
            <textarea name="output-case-1" id="output-case-1" placeholder="Output case #1" required></textarea>
          </div>
        </div>

        <button class="btn btn-primary" type="button" onclick="AddCase()">Add case</button>

        <p>Select file to be graded:</p>
        <input type="file" name="fileToUpload" id="fileToUpload">
        <button class="btn btn-primary" type="submit" onclick="Grade()">Grade</button>
      </form>

    <div id="grading-messages"></div>
    </div>
  </section>

  <section id="contact">
  <div class="container" id="container-contact">
    <h1>Any problem? Contact me here</h1>
    <form id="ajax-contact" method="post" action="mailer.php">
      <div class="field-control">
        <div class="field transparent">
          <input type="text" id="name" name="name" placeholder="Name" required>
        </div>
      </div>

      <div class="field-control">
        <div class="field transparent">
          <input type="email" id="email" name="email" placeholder="Email" required>
        </div>
      </div>

      <div class="field-control">
        <div class="field transparent">
          <textarea id="message" name="message" placeholder="Message" required></textarea>
        </div>
      </div>

      <div class="field transparent">
        <button class="btn btn-primary" type="submit" onclick="Send()">Send</button>
      </div>
    </form>

    <div id="contact-messages"></div>
  </div>
  </section>

  <footer class="footer">
    <div class="container">
      <p class="text-muted">2015 © Copyright <a href="github.com/icalf">Afrizal Fikri</a></p>
    </div>
  </footer>

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js" type="text/javascript" charset="utf-8" async defer></script>
  <script src="/js/apps.js" type="text/javascript" charset="utf-8" async defer></script>
</body>
</html>