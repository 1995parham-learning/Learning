use pnet::packet::ip::IpNextHeaderProtocols;
use pnet::transport::{icmp_packet_iter, transport_channel, TransportChannelType};
use std::process;

fn main() {
    let (_, mut rx) = transport_channel(
        1024,
        TransportChannelType::Layer3(IpNextHeaderProtocols::Icmp),
    )
    .unwrap_or_else(|err| {
        println!("failed to listen for icmp packets, {}", err);
        process::exit(1);
    });

    let mut icmp_reciever = icmp_packet_iter(&mut rx);

    loop {
        match icmp_reciever.next() {
            Ok((packet, ip)) => {
                println!("packet from {}", ip);
                println!("icmp type {}", packet.get_icmp_type().0);
            }
            Err(err) => {
                println!("failed to read a packet, {}", err);
            }
        }
    }
}
