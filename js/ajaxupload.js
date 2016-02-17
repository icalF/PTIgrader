function upload() {
  var formData = new FormData();
  var form = $(':file')[0];
  formData.append('file', form.files[0]);

  $.ajax({
    url : 'upload.php',
    type : 'POST',
    data : formData,
    xhr: function() {  // custom xhr
      myXhr = $.ajaxSettings.xhr();
      if(myXhr.upload) { // if upload property exists
        myXhr.upload.addEventListener('progress', function (event) {
          if (event.lengthComputable) {
            var percentComplete = event.loaded / event.total;

            //Do something with upload progress
            $('#uploadStatus').text('Uploading ..... '+percentComplete+'%');
          }
        }, false);
      }
      return myXhr;
    },
    error: function(xhr, stat, err) {
      alert(xhr.responseText);
      $('#uploadStatus').text('');
    },
    processData: false,  // tell jQuery not to process the data
    contentType: false,  // tell jQuery not to set contentType
    success : function(data) {
      addFile(getBasename(data), data);
      $('#uploadStatus').text("The file "+getBasename(data)+" has been uploaded.");
    }
  });
};

function getBasename(dir) {
  return dir.substring(18);
}