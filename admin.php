<?php 
if ($_SERVER['SERVER_ADDR'] != $_SERVER['REMOTE_ADDR']) {
  $this->output->set_status_header(400, 'No Remote Access Allowed');
  exit; //just for good measure
}

$conn = new mysqli('localhost', 'root', '', 'grader');
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
$sql = "SELECT * FROM response";
$result = $conn->query($sql);
while($row = $result->fetch_assoc()) 
{
  echo "Name: " . $row["name"]. "<br>Email: " . $row["email"]. "<br>Message: " . $row["content"]. "<br><br><br>";
}