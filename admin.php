<?php 
$conn = new mysqli('localhost', 'root', '', 'grader');
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT * FROM response";
$result = $conn->query($sql);

while($row = $result->fetch_assoc()) {
  echo "Name: " . $row["name"]. "<br>Email: " . $row["email"]. "<br>Message: " . $row["content"]. "<br>";
}
?>