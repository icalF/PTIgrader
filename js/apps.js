$(function() {
  $('a[href*="#"]:not([href="#"])').click(function() {
    if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
      var target = $(this.hash);
      target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
      if (target.length) {
        $('html, body').animate({
          scrollTop: target.offset().top
        }, 700);
        return false;
      }
    }
  });
});

var addCase = function() {
  var n = $('.case').length + 1;

  $('#ajax-grade .case:last').append(
    '<div class="case">'+
      'Case #'+n+
      '<div>'+
        '<div class="col-md-5 block">'+
          '<textarea name="input-case-'+n+'" id="input-case-'+n+'" placeholder="Input case #'+n+'" required></textarea>'+
        '</div>'+
        '<div class="col-md-2 block"></div>'+
        '<div class="col-md-5 block">'+
          '<textarea name="output-case-'+n+'" id="output-case-'+n+'" placeholder="Output case #'+n+'" required></textarea>'+
        '</div>'+
      '</div>'+
    '</div>'
  );
};