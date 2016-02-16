var app = angular.module("pti-grader", []);

app.controller("gradeCtrl", function($scope) {
  $scope.firstName = "John";
  $scope.lastName = "Doe";
});

$(':file').change(function () {
  var formData = new FormData();
  formData.append('file', this.files[0]);

  $.ajax({
    url : 'upload.php',
    type : 'POST',
    data : formData,
    // xhr: function() {  // custom xhr
    //   // myXhr = $.ajaxSettings.xhr();
    //   // if(myXhr.upload){ // if upload property exists
    //   //     myXhr.upload.addEventListener('progress', progressHandlingFunction, false); // progressbar
    //   // }
    //   // return myXhr;
    // },
    error: function(xhr, stat, err) {
      alert(xhr.responseText);
    },
    processData: false,  // tell jQuery not to process the data
    contentType: false,  // tell jQuery not to set contentType
    success : function(data) {
       console.log(data);
       alert(data);
    }
  });

  this[0].reset();
});