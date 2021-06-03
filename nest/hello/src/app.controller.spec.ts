import { Test, TestingModule } from '@nestjs/testing';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { SayDto } from './say.dto';

describe('AppController', () => {
  let appController: AppController;

  beforeEach(async () => {
    const app: TestingModule = await Test.createTestingModule({
      controllers: [AppController],
      providers: [AppService],
    }).compile();

    appController = app.get<AppController>(AppController);
  });

  describe('root', () => {
    it('should return "Hello Elahe!"', () => {
      expect(appController.getHello()).toBe('Hello Elahe!');
    });

    it('should return "Hello Parham!"', () => {
      const req = new SayDto();
      req.name = 'Parham';

      expect(appController.sayHello(req)).toBe('Hello Parham!');
    });
  });
});
