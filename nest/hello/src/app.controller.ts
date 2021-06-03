import { Controller, Get, Post, Body } from '@nestjs/common';
import { AppService } from './app.service';
import { SayDto } from './say.dto';

@Controller()
export class AppController {
  constructor(private readonly appService: AppService) {}

  @Get()
  getHello(): string {
    return this.appService.getHello();
  }

  @Post()
  sayHello(@Body() req: SayDto): string {
    return this.appService.getHello(req.name);
  }
}
