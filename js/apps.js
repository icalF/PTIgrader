// $(function() {
//   // Get the form.
//   var form = $('#ajax-contact');

//   // Get the messages div.
//   var formMessages = $('#form-messages');

//   // TODO: The rest of the code will go here...
// });

var addCase = function() {
  var n = $('.case').length + 1;

  $('#ajax-grade .case:last').append(
    '<div class="case">'+
      'Case #'+n+
      '<div class="field">'+
        '<textarea name="input-case-'+n+'" id="input-case-'+n+'" placeholder="Input case #'+n+'" required></textarea>'+
      '</div>'+
      '<div class="field">'+
        '<textarea name="output-case-'+n+'" id="output-case-'+n+'" placeholder="Output case #'+n+'" required></textarea>'+
      '</div>'+
    '</div>'
  );
};