package codinglaboratory.test.Controller;

import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.util.concurrent.atomic.AtomicLong;

@RestController
public class FileController {
    private final AtomicLong counter = new AtomicLong();
    @PostMapping("/file")
    public String upload(@RequestParam("files") MultipartFile file) throws Exception {
        File dest = new File("C:\\Users\\user\\Downloads\\"+file.getOriginalFilename()); // 다운로드 폴더로 저장 위치를 정함
        file.transferTo(dest); // 파일 업로드 작업 수행
        return "upload "+"경로는 C:\\Users\\user\\Downloads\\"+file.getOriginalFilename();
    }
}