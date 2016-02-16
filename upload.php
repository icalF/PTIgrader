<?php
$target_dir = "cpp/";
// echo $_FILES["fileToUpload"]["name"];
$name = $_FILES["file"]["name"];

$target_file = $target_dir . basename($name);
// $uploadOk = 1;
$fileType = pathinfo($target_file, PATHINFO_EXTENSION);
// echo $target_file;

// Check whether cpp valid
if ($fileType != "cpp") 
{
  http_response_code(400);
  echo "Sorry, only C++ source file are allowed";
} else 
{
  if (move_uploaded_file($_FILES["file"]["tmp_name"], $target_file)) 
  {
    echo "The file ". basename( $name). " has been uploaded.";
  } else 
  {
    http_response_code(500);
    echo "Sorry, there was an error uploading your file.";
  }
}
