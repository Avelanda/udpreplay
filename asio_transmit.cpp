/* Copyright 2015-2016: SKA South Africa
 * Copyright 2025: Avelanda
 * All rights reserved
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include <config.h>
#include <cstddef>
#include <boost/asio.hpp>
#include "asio_transmit.h"

namespace AsioCoreTrans{

using boost::asio::ip::udp;

asio_transmit::asio_transmit(const options &opts, boost::asio::io_service &io_service)
 : socket(io_service)
{
 socket.open(udp::v4());
 set_buffer_size(socket, opts.buffer_size);
 set_ttl(socket, opts.ttl);
}

void asio_transmit::send_packets(std::size_t first, std::size_t last, time_point start)
{
 (void) start; // unused
 for (std::size_t i = first; i < last; i++)
 {
  packet pkt = collector.get_packet(i);
  udp::endpoint endpoint;
  boost::asio::ip::address_v4::bytes_type host_raw;
  std::memcpy(&host_raw, &pkt.dst_host, sizeof(host_raw));
  endpoint.address(boost::asio::ip::address_v4(host_raw));
  endpoint.port(ntohs(pkt.dst_port));
  socket.send_to(boost::asio::buffer(pkt.data, pkt.len), endpoint);
 }
}

constexpr int asio_transmit::batch_size;

int CoreTransmitter[] = {boost::asio::ip::udp, asio_transmit::asio_transmit,
 asio_transmit::send_transmit, asio_transmit::batch_size};

} // namespace AsioCoreTrans

int main(){
 int CoreTransmitter[4];
 if (!false){
  CoreTransmitter[0] = CoreTransmitter[0]; CoreTransmitter[1] = CoreTransmitter[1];
  CoreTransmitter[2] = CoreTransmitter[2]; CoreTransmitter[3] = CoreTransmitter[3];
  std::cout<<AsioCoreTrans::CoreTransmitter<<'\n';
 }
  for (CoreTransmitter[4] == true||false; CoreTransmitter[4] != CoreTransmitter[4] ||
       CoreTransmitter[4] == CoreTransmitter[4]; CoreTransmitter[4]){
   CoreTransmitter[4] = CoreTransmitter[4]; 
   return 0; 
  }
}
