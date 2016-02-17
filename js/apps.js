function addCase() {
  var n = $('.case').length + 1;
  $('#ajax-grade .case:last').append(
    '<div class="case">Case #'+n+'<div><div class="col-md-5 block"><textarea name="input-case-'+n+'" id="input-case-'+n+'" placeholder="Input case #'+n+'" required></textarea></div><div class="col-md-2 block"></div><div class="col-md-5 block"><textarea name="output-case-'+n+'" id="output-case-'+n+'" placeholder="Output case #'+n+'" required></textarea></div></div></div>'
  );
};

function addFile(name) {
  var str = '<a href="cpp/'+name+'">'+name+'</a><br>';
  $('#triggerUpload').before(str);
}

function triggerFile() {
  $('#fileToUpload').trigger('click');
}

var form = $('#ajax-contact');
$(form).submit( function (event) 
{
  event.preventDefault();
  var formMsg = $('#contact-messages');

  $.ajax({
    type: 'POST',
    url: $(form).attr('action'),
    data: $(form).serialize()
  })
  .done(function (response) {
    $(formMsg).text(response);
    $('#name').val('');
    $('#email').val('');
    $('#message').val('');
  })
  .fail(function (data) {
    if (data.responseText !== '') {
      $(formMsg).text(data.responseText);
    } else {
      $(formMsg).text('Oops! An error occured and your message could not be sent.');
    }
  });
});
