import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  getHello(to = 'Elahe'): string {
    return `Hello ${to}!`;
  }
}
