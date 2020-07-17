use actix_web::{App, HttpResponse, HttpServer, Responder, get, web};

struct From {
    from: String
}

impl From {
    pub fn new(from: &str) -> Self {
        From {
            from: String::from(from),
        }
    }

    pub fn from(&self) -> &str {
        self.from.as_str()
    }
}

#[get("/hello")]
async fn hello(data: web::Data<From>) -> impl Responder {
    HttpResponse::Ok().json(
        format!("Hi Elahe ✋ from {}", data.from())
        )
}

#[actix_rt::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new().data(From::new("Parham")).service(hello)
    })
    .bind("127.0.0.1:1378")?
    .run()
    .await
}
