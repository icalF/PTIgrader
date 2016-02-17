<?php
session_start();
$id = $_SESSION["id"];

$target_dir = "cpp/" . $id . '/';
if (!is_dir($target_dir)) {
  mkdir($target_dir);
}

$name = $_FILES["file"]["name"];

$target_file = $target_dir . basename($name);

$fileType = pathinfo($target_file, PATHINFO_EXTENSION);

// Check whether cpp valid
if ($fileType != "cpp") 
{
  http_response_code(400);
  echo "Sorry, only C++ source file are allowed";
} else 
{
  if (move_uploaded_file($_FILES["file"]["tmp_name"], $target_file)) 
  {
    echo $target_file;
  } else 
  {
    http_response_code(500);
    echo "Sorry, there was an error uploading your file.";
  }
}
