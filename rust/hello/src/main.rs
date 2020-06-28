use actix_web::{App, HttpResponse, HttpServer, Responder, get};

#[get("/hello")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().json("Hey there!")
}

#[actix_rt::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new().service(hello)
    })
    .bind("127.0.0.1:8088")?
    .run()
    .await
}
