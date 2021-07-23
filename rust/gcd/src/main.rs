use actix_web::{web, App, HttpResponse, HttpServer};
use serde::Deserialize;

fn main() {
    let server = HttpServer::new(|| {
        App::new()
            .route("/", web::get().to(get_index))
            .route("/gcd", web::post().to(post_gcd))
    });

    println!("serving on http://127.0.0.1:1378...");
    server
        .bind("127.0.0.1:1378")
        .expect("error binding server to address")
        .run()
        .expect("error running server")
}

fn get_index() -> HttpResponse {
    HttpResponse::Ok().content_type("text/html").body(
        r#"
        <html>
        <head>
        <title>GCD Caculator</title>
        </head>
        <body>
        <form action="/gcd" method="post">
        <input type="text" name="n" />
        <input type="text" name="m" />
        <button type="submit">Compute GCD</button>
        </form>
        </body>
        </html>
    "#,
    )
}

#[derive(Deserialize)]
struct GcdParams {
    n: u64,
    m: u64,
}

fn post_gcd(form: web::Form<GcdParams>) -> HttpResponse {
    if form.n == 0 || form.m == 0 {
        return HttpResponse::BadRequest().content_type("text/html").body(
            r#"
        <html>
        <head>
        <title>GCD Caculator</title>
        </head>
        <body>
            <h6>Computing the GCD with zero is boring."</h6>
        </body>
        </html>
    "#,
        );
    }

    let response = format!(
        "The greatest common divisor of the numbers {} and {} is <b>{}</b>",
        form.n,
        form.m,
        gcd(form.n, form.m)
    );

    HttpResponse::Ok().content_type("text/html").body(format!(
        "
        <html>
        <head>
        <title>GCD Caculator</title>
        </head>
        <body>
    {}
        </body>
        </html>",
        response
    ))
}

fn gcd(a: u64, b: u64) -> u64 {
    assert!(a != 0 && b != 0);

    if a % b == 0 {
        b
    } else {
        gcd(b, a % b)
    }
}

#[test]
fn test_gcd() {
    assert_eq!(gcd(14, 15), 1);
    assert_eq!(gcd(14, 7), 7);
}
