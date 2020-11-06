use actix_web::{get, web, App, HttpResponse, HttpServer, Responder};

const HOST: &str = "127.0.0.1";
const PORT: u32 = 1378;

struct From {
    from: String,
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
    HttpResponse::Ok().json(format!("Hi Elahe ✋from {}", data.from()))
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    println!("listen on {}:{}", HOST, PORT);
    HttpServer::new(|| {
        let api = web::scope("/api").data(From::new("Parham")).service(hello);
        App::new().service(api)
    })
    .bind(format!("{}:{}", HOST, PORT))?
    .run()
    .await
}
